import java.util.*;

public class LongestPalindromicSubsequence {

private static int max( int a, int b){
    return a>b?a:b;
}

public static int lps(String seq){
    int len = seq.length();

    if( len == 0)
        return 0;

    int [][] max_len = new int[20][20];
    max_len[0][0] = 0;
    
    for(int i = len-1; i >= 0; i--){
        for(int j = i;j < len; j++){
            
            if( i == j )
                max_len[i][j] = 1;
            else if( j - i == 1){
                if(seq.charAt(i) == seq.charAt(j) )
                    max_len[i][j] = 2;
                else
                    max_len[i][j] = 1;
            }
            else{
                if(seq.charAt(i) == seq.charAt(j) )
                    max_len[i][j] = max_len[i + 1][j - 1] + 2;
                else
                    max_len[i][j] = max(max_len[i + 1][j], max_len[i][j - 1]);
            }
        }
    }

    return max_len[0][len-1];

}

public static void main(String [] args){

    String seq = "GEEKS FOR GEEKS";

    int res = lps(seq);
    System.out.println(Integer.toString(res));


}

}
