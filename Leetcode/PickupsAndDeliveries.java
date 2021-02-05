package Leetcode;

public class PickupsAndDeliveries {
    /*
        https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/submissions/
    */
    
    public static long findUniqueSequence_DP(int N) {
        long[][] cnt = new long[N + 1][N + 1];
        cnt[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            cnt[i][0] = i * cnt[i-1][0];
            for (int j = 1; j <= i; ++j) {
                cnt[i][j] = 0;
                if (j < i) {
                    cnt[i][j] += cnt[i-1][j] * (N -i + 1);
                }
                if (j <= i) {
                    cnt[i][j] += cnt[i][j-1] * (i - j + 1);
                }
            }
        }
        return cnt[N][N];
    }

    public static long findUniqueSequence(int N) {
        if (N == 1) {
            return 1;
        }
        return N * (2 * N - 1) * findUniqueSequence(N - 1);
    }


    public static void main(String[] args) {
        System.out.println("Count("+1+")="+findUniqueSequence(1));
        
        System.out.println("Count("+2+")="+findUniqueSequence(2));
        
        System.out.println("Count("+3+")="+findUniqueSequence(30));
    }
}
