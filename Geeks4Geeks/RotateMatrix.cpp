#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


void rotateMatrix(int a[][100], int N){
    
    int temp;
    for(int i =0;i< N;i++){
        for(int j =i+1;j< N;j++){

            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i =0;i< N;i++){
        for(int j =0;j<N/2 ;j++){
            temp = a[i][j];
            a[i][j] = a[i][N-j-1];
            a[i][N-j-1] = temp;
        }
    }

    return;
}

void printMatrix(int arr[][100], int N){

    for(int i =0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }

    return;
}

int main(){

    int N;
    scanf("%d",&N);

    int arr[100][100];

    for(int i =0;i< N;i++){
        for(int j =0;j< N;j++){
            scanf("%d",&arr[i][j]);
        }
    }


   printMatrix(arr,N);
   rotateMatrix(arr,N);
   printMatrix(arr,N);


   return 0;
}
