// Topcoder SRM 441 - Div2

public class PerfectPermutationHard{

    private int findNextUnvisited(boolean [] visited, int index){

        for(int ind=index;ind<visited.length();ind++)
        {
            if( !visited[ind] )
                return ind;
        }
        return -1;

    }

    private int [] parent( int [] child){

        return;
    }

    public int [] reorder( int [] P){

        int len = P.length();
        boolean [] visited = new boolean[ len ];

        child[0] = 0;
        visited[0] = true;
        c_ind = 1;

        while(P[child[c_ind-1]] != 0 ){
            child[c_ind] = P[child[c_ind-1]];
            visited[child[c_ind]] = true;
            c_ind++;
        }

        if(c_ind == len)
            return P;

        int cur_unvisited = findNextUnvisited(visited, 1);
        
        while(cur_unvisited < len){

            while(!visited[cur_unvisited]){
                child[c_ind] = cur_unvisited;
                c_ind++;
                visited[cur_unvisited] = true;
                cur_unvisited = P[cur_unvisited];
            }

            cur_unvisited = findNextUnvisited(visited, cur_unvisited + 1);
        }

        return parent(child);
    }
            



