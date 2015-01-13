#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int findLength(int arr[], int N){
    
    if(arr == NULL || N == 0)
        return 0;

    int sum[N];
    sum[0]=arr[0];
    for(int i = 1;i<N;i++)
        sum[i] = sum[i-1]+arr[i];


    int l;
    if( N% 2 == 0)
        l = N;
    else 
        l = N-1;
    
    for(int len = l;len>= 0;len-=2){

        for(int i = 0;i<=N-len; i++){

            int ind = i + len -1;
            int totSum = sum[ind] ;
            int halfSum = sum[ind/2];
            
            if(i != 0){
                totSum -= sum[i-1];
                halfSum -= sum[i-1];
            }

            if( 2*halfSum == totSum)
                return len;
            }
    }

    return 0;
}
int main(){

    int arr[] = {1,5,3,8,0,2,3};

    cout<<findLength(arr,7)<<"\n";

    return 0;

}

