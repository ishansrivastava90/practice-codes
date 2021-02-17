package Leetcode;

public class ShortestPalindrome {
    
    /*
    Example: 1. ad. a bacz da
                  adzc  ad ba czda
             2. aa cec aa a
             3.  b. aab ba baab
             4. aababab abababa  
    */

    public static String shortestPalindrom_KMP(String s) {
        String revS = new StringBuilder(s).reverse().toString();
        String newS = s + "#" + revS;

        int[] lps = new int[newS.length()];
        lps[0] = 0;
        for (int i = 1; i < newS.length(); ++i) {
            int k = lps[i-1];

            while (k > 0 && (newS.charAt(i) != newS.charAt(k))) {
                k = lps[k-1];
            }
            if (newS.charAt(i) == newS.charAt(k)) {
                ++k;
            }
            lps[i] = k;
        }
        //System.out.println(newS);
        //for(int i = 0; i < lps.length; ++i)
            //System.out.print(lps[i] +", ");
        
        return revS.substring(0, revS.length() - lps[lps.length-1]) + s;
    }

    public static String shortestPalindrome_incorrect(String s) {
        if (isPalindrome(s)) {
            return s;
        }
        StringBuffer sb = new StringBuffer();
        int i = 0;
        int j = s.length() - 1;
        int k = j;
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
            }
            else {
                char prev = s.charAt(k);
                boolean charChanged = prev != s.charAt(j);
                for (int it = k-1; it >= j; it--) {
                    if (prev != s.charAt(it)) {
                        charChanged = true;
                        break;
                    }
                }
                if (charChanged) {
                    while (k >= j) {
                        sb.append(s.charAt(k--));
                        i = 0;
                    }
                }
                else {
                    sb.append(s.charAt(j));
                    k = j - 1;
                }
            }
            j--;
        }
        return sb.toString() + s;
    }

    public static boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
