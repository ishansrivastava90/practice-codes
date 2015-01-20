#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;

typedef struct node{

    int val;
    int ind;
} node;

typedef struct compare{

    bool operator()(const node& l, const node&r){
        return l.val > r.val;
    }
} compare;

void flip(int arr[], int ind, int N){

    if( N == 0 || ind >= N)
        return;
    int end = (ind+N-1)/2;
    if((ind+N-1) % 2 == 0)
        end--;
    for(int i = ind; i<=end;i++){
        arr[N-1-i+ind] = arr[N-1-i+ind] + arr[i];
        arr[i] = arr[N-1-i+ind] - arr[i];
        arr[N-1-i+ind] = arr[N-1-i+ind] - arr[i];
    }
    return;
}

node createNewNode(int val, int ind){

    node n;
    n.val = val;
    n.ind = ind;

    return n;
}

int main(){

    int N;
    scanf("%d",&N);

    int arr[100];
    
    priority_queue<node, vector<node>, compare > min_heap;
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        min_heap.push(createNewNode(arr[i],i));
    }


    for(int i = 0;i<N; i++){
        node min = min_heap.top();
//        cout<<min.val<< " "<<min.ind<<"\n";
        min_heap.pop();

        flip(arr,min.ind + i,N);
        flip(arr,i,N);
        flip(arr,i+1,N);
        flip(arr,min.ind+1+i,N);

    }

    for(int i =0;i<N;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";



    return 0;

}
