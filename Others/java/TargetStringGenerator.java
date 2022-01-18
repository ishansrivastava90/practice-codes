public class TargetStringGenerator {

    /*
        https://leetcode.com/discuss/interview-question/426697/uber-online-assessment-questions
        Q1
    */
    public static int GetGeneratedCount(String[] src, String target) {
        int srcLen = src[0].length();
        int[][] memo = new int[target.length()][srcLen];

        return NumWays(0, 0, src, srcLen, target, memo);
        
    }

    public static int NumWays(int tInd, int sInd, String[] src, int srcLen, String t, int[][] memo) {

        if (tInd == t.length()) {
            return 1;
        }
        if (sInd == srcLen) {
            return 0;
        }
        if (memo[tInd][sInd] != 0) {
            return memo[tInd][sInd];
        }

        char c = t.charAt(tInd);
        int totalCount = 0;
        int cnt = 0;
        for (String s : src) {
            if (s.charAt(sInd) == c) {
                cnt++;
            }
        }

        if (cnt > 0) {
            totalCount += cnt * NumWays(tInd + 1, sInd + 1, src, srcLen, t, memo);
        }
        totalCount += NumWays(tInd, sInd + 1, src, srcLen, t, memo);
        memo[tInd][sInd] = totalCount;
        return memo[tInd][sInd];

    }

    public static void main(String[] args) {
        System.out.println(GetGeneratedCount(new String[] {"adc", "aec", "efg"}, "ac"));
        
        System.out.println(GetGeneratedCount(new String[] {"valya", "lyglb", "vldoh"}, "val"));
    }
    
}
