public class ActivateFountains {

    public static int activate(int[] a) {
        int n = a.length;
        int[] t = new int[a.length];
        for (int i = 0; i < a.length; ++i) {
            int leftInd = Math.max(0 , i - a[i]);
            t[leftInd] = Math.max(t[leftInd], Math.min(i + a[i], n - 1));
        }
        
        int openTaps = 0;
        int maxReach = 0;
        int currReach = 0;
        int i = 0;
        while(i < n) {
            maxReach = Math.max(maxReach, t[i]);
            
            // Need to open another tap
            if (i == currReach) {
                openTaps++;
                currReach = maxReach;
                if (currReach >= n - 1)
                    break;
            }
            i++;
        }
        return i == n && currReach < n - 1 ? -1 : openTaps;
    }
    public static void main(String[] args) {
        System.out.println(activate(new int[] {0,0,0,3,0,0,2,0,0}));
    }
}