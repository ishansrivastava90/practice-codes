#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int find_lis(int arr[], int N){

    if(arr == NULL || N == 0)
        return 0;

    int lis[N+1];
    lis[0] = 1;
    for(int i = 1;i <= N; i++){
        lis[i] = -1;
        int max_val = -1;
        int max_ind = -1;
        for(int j = 0;j<i;j++){ 
            if(max_val < lis[j]){
                max_val = lis[j];
                max_ind = j;
            }
        }
        if(arr[i] > arr[max_ind])
            lis[i] = lis[max_ind] + 1;
        else
            lis[i] = lis[max_ind];
    }

    return lis[N];

}

int main(){

    int arr[] = { 10, 22, 9, 33, 21, 50, 51, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", find_lis( arr, n ) );

    return 0;
}
