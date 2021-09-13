#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


int up_bound(int arr[], int left, int right, int val,int index){
    if(left > right)
        return index;

    if( left == right && arr[left] == val)
        return left;

    int mid = (right+left)/2;

    if(arr[mid]<= val){
        left = mid+1;
        index = mid;
    }
    else
        right = mid-1;

    return up_bound(arr, left, right, val,index);

}

int lo_bound(int arr[], int left, int right, int val, int index){

    if(left> right)
        return index;

    if(left == right && arr[left] == val)
        return left;

    int mid = (right+left)/2;

    if(arr[mid] >= val)
    {
        right = mid-1;
        index = mid;
    }
    else
        left = mid +1;

    return lo_bound(arr,left, right, val,index);

    
}

int main(){

    int N, C;

    cin>>N>>C;
    
    int *arr = new int[100];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int numOfPairs = 0;

    for(int i = 0;i<N;i++){
        int right = up_bound(arr, i,N-1, arr[i]-C,-1);
        int left = lo_bound(arr,i,N-1,arr[i]-C,-1);
        
        if( left != -1 && right != -1)
            numOfPairs+= right - left;
    }
//
    cout<<"ANs"<<'\n';
    cout<<numOfPairs; 

    return 0;
}

