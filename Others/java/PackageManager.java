import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class PackageManager {

    static class PackageInfo {
        public static String IMPLICIT_INTSTALL = "implicit";        
        public static String EXPLICIT_INTSTALL = "explicit";

        public int RefCount;
        public String InstallMode;

        public PackageInfo(String installMode) {
            this(installMode, 0);
        }

        public PackageInfo(String installMode, int refCount) {
            RefCount = refCount;
            InstallMode = installMode;
        }
    }

    private HashMap<String, PackageInfo> InstalledPackages;
    private HashMap<String, List<String>> DependencyGraph;
    
    public PackageManager() {
        InstalledPackages = new HashMap<String, PackageInfo>();
        DependencyGraph = new HashMap<>();

    }
    /**
     * Generates package dependencies and keeps them in-memory for the lifecycle of the pm object
     */
    public void generateDependencies(String packageName, String... dependencies) {
        if (!DependencyGraph.containsKey(packageName) && !detectCycles(packageName, new HashSet<String>())) {
                DependencyGraph.put(packageName, Arrays.asList(dependencies));
        }
    }

    /**
     * Installs the packages and its dependecnies. Assumes that the dependency
     * graph has already been generated.
     */
    public String installPackage(String packageName) {
        if(InstalledPackages.containsKey(packageName)) {
            return "Package is already installed.";
        }

        InstalledPackages.put(packageName, new PackageInfo(PackageInfo.EXPLICIT_INTSTALL));
        
        // Recursively install dependencies
        installDependencies(packageName);
        return "Installing " + packageName;
    }

    public String removePackage(String packageName) {
        if (!InstalledPackages.containsKey(packageName)) {
            return packageName + " is not installed";
        }
        if (InstalledPackages.get(packageName).RefCount > 0) {
            return packageName + " is still needed.";
        }
        removeDependencies(packageName);
        return "";

    }

    private String installDependencies(String packageName) {
        if (!DependencyGraph.containsKey(packageName) || DependencyGraph.get(packageName).isEmpty()) {
            return "No dependencies for package: " + packageName;
        }

        for (String dep : DependencyGraph.get(packageName)) {
            if (InstalledPackages.containsKey(dep)) {
                InstalledPackages.get(dep).RefCount++;
            }
            else {
                InstalledPackages.put(dep, new PackageInfo(PackageInfo.IMPLICIT_INTSTALL, 1));
                installDependencies(dep);
            }
        }
        return "Dependencies installed!";
    }
    
    private String removeDependencies(String packageName) {
        if (!DependencyGraph.containsKey(packageName) || DependencyGraph.get(packageName).isEmpty()) {
            return "No dependencies for package: " + packageName;
        }        

        for (String dp : DependencyGraph.get(packageName)) {
            InstalledPackages.get(dp).RefCount--;
			PackageInfo packageInfo = (PackageInfo)InstalledPackages.get(dp);            

            if (packageInfo.RefCount == 0) {
                InstalledPackages.remove(dp);
                System.out.println("Removing" + dp  );                
            }
            removeDependencies(dp);
        }
        return "";
    }

    private boolean detectCycles(String packageName, HashSet<String>visited) {
        if (!DependencyGraph.containsKey(packageName) || DependencyGraph.get(packageName).isEmpty()) {
            return false;
        }
        visited.add(packageName);
        for(String dp : DependencyGraph.get(packageName)) {
            if (visited.contains(dp) || detectCycles(dp, visited)) {
                return true;
            }
        }
        visited.remove(packageName);
        return false;
    }
}

// TCP  -> NETCARD
// NETCARD -> TCP
