#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int find_change(int coins[], int numC, int N){

    if(coins == NULL || numC == 0 || N == 0)
        return 0;

    int ways[N+1][numC+1];

    for(int i=0;i<= N;i++){
        for(int j =0;j<=numC;j++){
            ways[i][j] = -1;
            if(i == 0 )
                ways[i][j] = 1;
            else if(j == 0 && i >= coins[0]){
                if(i % coins[0] == 0)
                    ways[i][0] = 1;
                else 
                    ways[i][0] = 0;
            }
        }
    }

    for(int i =1;i<=N; i++){
        for(int j = 1;j<numC;j++){

            if(i >= coins[j])
                ways[i][j] = ways[i-coins[j] ][j] + ways[i][j-1];
            else
                ways[i][j] = ways[i][j-1];
        }
    }

    return ways[N][numC-1];

}

int main(){
    int arr[] = { 2,5, 3,6};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 10;
    printf(" %d ", find_change(arr, m, n));
    return 0;
}
