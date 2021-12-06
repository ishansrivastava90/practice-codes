public class CountDigitOccurrences {

    // 0-9 --> 0:1, 2:1, 4:1
    // 10-99 --> 0:11, 2: 8 + 10, 4:
    // Count 0, 2, 4

    // dp[37][2] -> dp[3][2] * 10 +  
    public static int countOccur(int n) {
        // n = 26
        int total = 1; // starts from 1
        for (int i = 1; i <= n; ++i) {
            int num = i;
            while (num != 0) {
                int digit = num % 10;
                if (digit == 0 || digit == 2 || digit == 4) {
                    total++;
                }
                num = num / 10;

            }
        }
        return total;

    }

    public static void main(String[] args) {
        System.out.println(countOccur(30));
    }
}