// Topcoder SRM 441 Div 2
public class DifferentStrings {

    public int minimize(String A, String B){
        int lenA = A.length();
        int lenB = B.length();
        int diff;
        int min_diff = lenB;
        for(int it=0;it<=lenB-lenA;it++){
            diff = 0;
            for(int ind=0;ind<lenA;ind++){
                if(A.charAt(ind) != B.charAt(it+ind))
                    diff++;
            }
            if( diff < min_diff)
                min_diff = diff;
        }     
        return min_diff;
    }
}
