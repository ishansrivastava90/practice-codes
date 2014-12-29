import java.util.Scanner;
class StepfordHouse{



    private static int mergeSortHeights(int [] heights, int begin, int end, int N){

        if(begin == end)
            return 0;
        if(end-begin == 1){
            if(heights[begin] > heights[end])
            {
                heights[begin]+= heights[end];
                heights[end]= heights[begin]-heights[end];
                heights[begin]=heights[begin]-heights[end];
                return 1;
            }
            return 0;
        }

        int mid = (begin+end)/2;

        int d_count = mergeSortHeights(heights,begin,mid,mid-begin+1) + mergeSortHeights(heights,mid+1,end, end-mid);
       
        int [] tempHeights = new int [heights.length];
        for(int i = 0;i<heights.length;i++)
            tempHeights[i] = heights[i];

        int i=begin;
        int j= mid+1;
        int k = begin;
        while(i<=mid && j <= end){
            if(tempHeights[i] < tempHeights[j]){
                heights[k] = tempHeights[i];
                i++;
                k++;
            }
            else{
                heights[k] = tempHeights[j];
                j++;k++;
                d_count = d_count+ (mid-i+1);
            }

        }

        while(i<=mid){
            heights[k] = tempHeights[i];
            i++;
            k++;
        }
        while(j<=end){
            heights[k] = tempHeights[j];
            j++;
            k++;
        }
        
        return d_count;

    }

    private static void check(int [] heights){

        int N = heights.length;
        for(int i = 0 ;i<heights.length/2;i++)
            heights[i] = heights[N-1-i];
    
    }
    public static void main(String [] args){

        int N;

//        BufferedReader bufferRead = new BufferedReader( new InputStreamReader(System.in));
//        String s = bufferRead.readLine();
        Scanner in = new Scanner(System.in);
        N = in.nextInt();

        int [] heights = new int[N];
        for(int i=0;i<N;i++){
            heights[i] = in.nextInt();
        }
    
        int disorderCount = mergeSortHeights(heights,0,N-1,N);

        System.out.println(disorderCount+"");
//        for(int i = 0;i< N;i++)
//            System.out.println(heights[i]+"");
        
    
    }



}
