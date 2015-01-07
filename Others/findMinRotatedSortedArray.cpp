#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int findMinRSorted( int arr[15], int l, int r){

    if(arr = NULL )
        return -1;
    
    while(l<=r){
        cout<<"HELLO\n";

        int m = (l+r)/2;

        if(l == r)
            return arr[l];
        cout<<"HELLO1\n";

        if(arr[m] > arr[r])
            l = m+1;
        else if( arr[m] < arr[r])
            r = m-1;
        cout<<"HELLO2\n";
            
    }

    return -1;

}
int main(){
    
    int arr[15];
    int N;

    scanf("%d",&N);
    
    for(int i =0;i<N;i++)
        scanf("%d",&arr[i]);

    cout<<findMinRSorted(arr, 0, N-1);

    return 0;
}
