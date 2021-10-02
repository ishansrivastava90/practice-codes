import java.util.HashMap;

/* Problem:
N different couple goes to a cinema with 2N different seats. They take their place randomly. You could make swap operation.
Write a code for given input what is the minimum number of swap operations for sitting all couples with their partners? 
Additionally, be sure that no one swaps more than 2 times
*/
public class CouplePairSwap {

    // seats contain the initial arrangement of individuals. Couples are denoted by same number
    // [1,2,2,3,1,3]
    public int MinSwapsRequired(int[] seats) {
        HashMap<Integer, Integer> targetIndices = new HashMap<>();
        int swapsRequired = 0;

        for (int i = 0; i < seats.length; ++i) {
            if (targetIndices.containsKey(seats[i])) {
                // Partner has been seen before. Swap this person with the
                // person on the desired index adjacent to their partner 
                // 1 [2]|3 (1)...  --> 1 (1) | 3 [2]

                // Ensure that the current person is not already seated with their partner
                if (seats[i] != seats[targetIndices.get(seats[i])]) {
                    Swap(seats, i, targetIndices.get(seats[i]));
                    swapsRequired++;
                    targetIndices.put(seats[i], GetDesiredIndex(i));
                }
            }
            else {
                
                targetIndices.put(seats[i], GetDesiredIndex(i));
            }
        }
        return swapsRequired;
    }

    public int GetDesiredIndex(int currInd) {
        return (currInd % 2 == 0) ? (currInd + 1) :(currInd - 1);
    }

    public void Swap(int[] arr, int i, int j) {
        int a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
    }

    public static void main(String[] args) {
        // {1,2,2,3,1,3} -> {2,2,1,3,1,3} -> {2,2,1,1,3,3}
        int[] seats = new int[] {1,2,2,3,1,3};
        CouplePairSwap swapper = new CouplePairSwap();
        System.out.println(swapper.MinSwapsRequired(seats));  
        for (int p : seats) {
            System.out.print(p +", ");
        }      
    }
    
}
