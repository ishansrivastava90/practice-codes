package Leetcode;

public class CountingSteps {
    /* Ref: https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    */ 

    public static void main(String[] args) {
        System.out.println(climbStairs(5));
        // 5 stairs - 8 ways
        // 1,1,1,1,1
        // 1,1,1,2
        // 1,1,2,1
        // 1,2,1,1
        // 2,1,1,1
        // 1,2,2
        // 2,1,2
        // 2,2,1
    }

    public static int climbStairs(int n) {
        int numWays[] = new int[n+1];
        numWays[0] = 1;
        numWays[1] = 1;
        for (int i = 2; i <=n; ++i) {
            numWays[i] = numWays[i-1] + numWays[i-2];
        }
        return numWays[n];
    }
}