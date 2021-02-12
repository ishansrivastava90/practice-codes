package Leetcode;

public class MergeSortedArrays {
    /*
    Ref: https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a size equal
    to m + n such that it has enough space to hold additional elements from nums2.
    */

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        // Assumption: nums1.length == m + n

        int ind1 = m - 1;
        int ind2 = n - 1; 
        int finalIndex = nums1.length - 1;
        while (ind1 >= 0 && ind2 >= 0) {
            if (nums1[ind1] > nums2[ind2]) {
                nums1[finalIndex--] = nums1[ind1];
                ind1--;
            }
            else {
                nums1[finalIndex--] = nums2[ind2];
                ind2--;
            }
        }

        // Adding the remaining elements
        while (ind1 >= 0) {
            nums1[finalIndex--] = nums1[ind1];
            ind1--;
        }
        
        while (ind2 >= 0) {
            nums1[finalIndex--] = nums2[ind2];
            ind2--;
        }
    }    
}
