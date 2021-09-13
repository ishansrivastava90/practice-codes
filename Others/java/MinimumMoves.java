/*
https://www.lintcode.com/problem/1822/
Given a string S consisting of N letters 'a' or 'b'. In one move, you can swap one letter for the other
 ('a' for 'b' or 'b' for 'a'). You should return the minimum number of moves required to obtain a
 string containing no instances of three identical consecutive letters.
 */
public class MinimumMoves {

    public static int FindMoves(String s) {
        int l = s.length();
        int currInd = 0;
        int cnt = 0;
        while(currInd < l) {
            char c = s.charAt(currInd);
            int ind2 = currInd + 1;
            while (ind2 < l && s.charAt(ind2) == c) {
                ind2++;
            }

            cnt += (ind2 - currInd)/3;
            currInd = ind2;
        }
        return cnt;
    }

    public static void main(String[] args) {
        String s = "baaaaa";
        System.out.println(FindMoves(s));        
    }
    
}


