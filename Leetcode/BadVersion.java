package Leetcode;

public class BadVersion {
    /*
    Ref: https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/
    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product
    fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are 
    also bad.
    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
    
    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad 
    version. You should minimize the number of calls to the API.
    */

    public static int firstBadVersion(int numVersions) {
        // Simple binary search
        int startVersion = 1;
        int endVersion = numVersions;

        while(startVersion < endVersion) {
            int mid = (int) (endVersion - ((endVersion - startVersion) * 1.0) / 2.0);

            if (isBadVersion(mid)) {
                endVersion = mid;
            }
            else {
                startVersion = mid + 1;
            }
        }
        return isBadVersion(startVersion) ? startVersion : startVersion + 1;
    }

    // Provided as an external API
    private static boolean isBadVersion(int version) {
        return false;
    }
    
}
