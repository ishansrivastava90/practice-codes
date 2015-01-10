#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

int lcs_len[100][100];


int max(int a, int b){
    return a>b?a:b;
}

int lcs_recursive(char X[], char Y[], int lenX, int lenY){
    
    if(lenX == 0 || lenY == 0)
        return 0;
        
    int res;
    if(X[lenX - 1 ] == Y[lenY - 1]){
        if(lcs_len[lenX-1][lenY-1] == -1)
            lcs_len[lenX-1][lenY-1] = lcs_recursive(X,Y,lenX-1, lenY -1);
        res = lcs_len[lenX-1][lenY-1]+1;
    }
    else{
        if( lcs_len[lenX-1][lenY] == -1)
            lcs_len[lenX-1][lenY] = lcs_recursive(X,Y,lenX-1,lenY);
        if( lcs_len[lenX][lenY-1] == -1)
            lcs_len[lenX][lenY-1] = lcs_recursive(X,Y,lenX,lenY-1);

        res = max(lcs_len[lenX-1][lenY], lcs_len[lenX][lenY-1]);
    }

    lcs_len[lenX][lenY] = res;
    return res;
}

int lcs_iterative(char X[], char Y[], int lenX, int lenY){
    
    if(lenX == 0 || lenY == 0)
        return 0;

    int lcs_len[100][100];
    for(int i =0;i< 100;i++){
        for(int j=0;j<100;j++){
            lcs_len[i][j] = -1;
            if( i == 0 || j == 0)
                lcs_len[i][j] = 0;
        }
    }

    
   for(int i = 1;i<=lenX;i++){
       for(int j = 1; j<=lenY;j++){
           if( X[i-1]== Y[j-1])
               lcs_len[i][j] = lcs_len[i-1][j-1] +1;
           else
               lcs_len[i][j] = max(lcs_len[i-1][j], lcs_len[i][j-1]);
       }
   }

   return lcs_len[lenX][lenY];
}



int lcs(char X[], char Y[], int lenX, int lenY){
    if(lenX == 0 || lenY == 0)
        return 0;

    for(int i =0;i< 100;i++){
        for(int j=0;j<100;j++)
            lcs_len[i][j] = -1;
    }

    int len = lcs_iterative(X,Y,lenX, lenY);
    return len;
}

int main()
{
    char X[] = "AGXGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    getchar();
    return 0;
}
