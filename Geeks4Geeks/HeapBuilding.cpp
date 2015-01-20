#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

class MinHeapBuilder{

    int N;
    int *heap;

    public:


    MinHeapBuilder(int N){

        this->N = N;
        this->heap = (int*)malloc(sizeof(int)*N);

    }

    int* getMinHeap(){
        return this->heap;
    }

    void build(int *arr){

        // Throw Exception
        if(arr == NULL)
            return;

        for(int i =0;i< this->N; i++)
            this->heap[i] = arr[i];

        for(int i = N-1;i >=0;i--){

            int parInd = i/2;
            if(i % 2 ==0)
                parInd--;

            if( this->heap[i] < this->heap[parInd])
                heapify(i);
        }

    }

    void heapify(int ind){
        
        if( ind == 0)
            return;

        while(ind > 0){

            int parInd;
            if(ind%2 == 0)
                parInd = ind/2 -1;
            else
                parInd = ind/2;

            if(this->heap[ind] < this->heap[parInd]){
                int temp = this->heap[ind];
                this->heap[ind] = this->heap[parInd];
                this->heap[parInd] = temp;
                ind = parInd;
            }
            else
                break;

        }

        return;        
    }
};


int main(){

    int N;

    scanf("%d",&N);

    int arr[100];
    for(int i =0;i<N;i++)
        scanf("%d",&arr[i]);


    MinHeapBuilder *mhb = new MinHeapBuilder(N);
    mhb->build(arr);

    int * h = mhb->getMinHeap();
    for(int i =0;i<N;i++)
        cout<<h[i]<<" ";
    cout<<"\n";

    return 0;
}



