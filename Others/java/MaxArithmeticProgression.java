import java.util.HashSet;

/*https://leetcode.com/discuss/interview-question/793514/robinhood-assessment-questions-2020*/
public class MaxArithmeticProgression
{

    // Special case when a is empty and all the elements come from B:
    public static int largestAPInB(int[] b) {
        return 0;
    }
    public static int maxAP(int[] a, int[] b) {
        if (a.length == 0 && b.length == 0) {
            return -1;
        }
        else if (a.length == 0) {
            return largestAPInB(b);
        }

        // if a is empty, return the count of largest AP in B
        int increment = Integer.MAX_VALUE;
        for (int i = 0; i + 1 < a.length; ++i) {
            increment= Math.min(increment, a[i+1] - a[i]);
        }
        HashSet<Integer> setA = new HashSet<>();
        for (int i = 0; i < a.length; ++i) {
            setA.add(a[i]);
        }
        HashSet<Integer> setB = new HashSet<>();
        for (int i = 0; i < b.length; ++i) {
            setB.add(b[i]);
        }

        int prev = a[0];
        int res = Integer.MIN_VALUE;
        for (int k = 0; k <= increment; ++k) {
            // go forward            
            int fromA = 1;
            int included = 0;
            while (true) {
                int curr = prev + k;
                if (setA.contains(curr)) {
                    prev = curr;
                    included++;
                    fromA++;
                    continue;
                }
                if (setB.contains(curr)) {
                    included++;
                    prev = curr;
                    continue;
                }
                break;
            }

            // go backward
            int curr = a[0];
            while (setB.contains(curr - k)) {
                curr = curr - k;
                included++;
            }
            res = Math.max(res, fromA < a.length ? -1: included);
        }
        
        return res;
    }

    public static void main(String[] args) {
        int[] a = new int[] {5, 7, 13, 14}; //{2, 4, 8};//{0, 4, 8, 16};
        int[] b= new int[] {9, 11, 15}; //{1, 6, 10, 12}; //{0, 2, 6, 12, 14, 20};

        System.out.println(maxAP(a, b));
    }
}

