package Leetcode;

import java.lang.System;

public class MaximumSumArray {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        System.out.println(maxSubArray(new int[] {-2, 1, -3, 4, -1, 2, 1,-5, 4}));
        
        return;    
    }

    public static int maxSubArray(int[] nums) {

        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        int globalMax = sum[0];
        for (int i = 1; i < nums.length; ++i) {
            sum[i] = Integer.max(nums[i], sum[i-1] + nums[i]);
            if (sum[i] > globalMax) {
                globalMax = sum[i];
            }
        }
        return globalMax;
    }

}