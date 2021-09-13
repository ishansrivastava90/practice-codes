import java.util.HashMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* Tesla Coding challenge */
public class ComputeTestResults {

    public static final String OK = "OK";
    public static final String WRONG = "Wrong answer";    
    public static final String TLE = "Time limit exceeded";
    public static final String RUNTIME_ERR = "Runtime error";

    public static String ExtractTaskname(String s) {
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isDigit(s.charAt(i))) {
                return s.substring(0, i);
            }
        }
        return s;
    }

    public static String CombineResult(String groupResult, String testResult) {
        if (testResult == OK) {
            return groupResult.isEmpty() ? OK : groupResult; // Retain the overall result for errors
        }
        return testResult; // Override the group result to now show err
    }

    public static int ComputeScore(String[] testcases, String[] results) {
        String taskName = ExtractTaskname(testcases[0]);
        int taskNameLen = taskName.length();
        final Pattern digitPattern = Pattern.compile("\\d+");

        HashMap<Integer, String> resultMap = new HashMap<>();
        int maxGroupId = 1;
        for (int i = 0; i < testcases.length; ++i) {
            String fulltestcase = testcases[i];
            String testresult = results[i];

            String testcase = fulltestcase.substring(taskNameLen);
            Matcher m = digitPattern.matcher(testcase);
            m.find();  // Guaranteed to have 1 group matching the group
            int group = Integer.parseInt(m.group());

            // Check if this is more than the recorded max group Id
            maxGroupId = Math.max(maxGroupId, group);

            // Update results map
            String groupResult = resultMap.getOrDefault(group, "");
            resultMap.put(group, CombineResult(groupResult, testresult));
        }

        int successCount = 0;
        for (int group = 1; group <= maxGroupId; ++group) {
            if (resultMap.get(group) == OK) {
                successCount++;
            }
        }

        return (successCount * 100)/maxGroupId;
    }

    public static void main(String[] args) {
        String s = "test1a";
        System.out.println(ExtractTaskname(s));
        
        /*String[] testcases = new String[] {
            "test1a", "test2", "test1b", "test1c", "test3"
        };
        String[] res = new String[] {
            WRONG, OK, RUNTIME_ERR, OK, TLE
        };*/

        String[] testcases2 = new String[] {
            "codility1", "codility3", "codility2", "codility4b", "codility4a"
        };
        String[] res2 = new String[] {
            WRONG, OK, OK, RUNTIME_ERR, OK, OK
        };
        System.out.println(ComputeScore(testcases2, res2));
    }
}





