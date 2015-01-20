#include<stdio.h>
#include<iostream>
#include<stdio.h>

int max(int a, int b){
    return a>b?a:b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int knapsack(int W, int *wt, int *val, int N){

    if( W == 0 || wt == NULL || val == NULL || N == 0)
        return 0;

    int max_val[500][10];
    for(int i=0;i<500;i++){
        for(int j =0;j<10;j++)
            if( i ==0 || j == 0)
                max_val[i][j]=0;
    }

    for(int w = 1; w <= W; w++){
        for(int i = 1;i< N;i++){
            if(w >= wt[i])
                max_val[w][i] = max(max_val[w-wt[i]][i-1] + val[i], max_val[w][i-1]);
            else
                max_val[w][i] = max_val[w][i-1];
        }
        
    }

    return max_val[W][N-1];

}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
