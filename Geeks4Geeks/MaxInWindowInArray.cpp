#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<deque>

using namespace std;

int main(){

    int N, K;
    scanf("%d%d",&N,&K);

    int a[20];
    deque<int> max_deque(K);
    
    for(int i =0;i<N;i++){
        scanf("%d",&a[i]);
        if(i < K){
            while(!max_deque.empty() && a[max_deque.back()] < a[i])
                max_deque.pop_back();

            max_deque.push_back(i);
        }
    }

    for(int i = K;i<N;i++){

        cout<<a[max_deque.front()]<<"\n";

        while(!max_deque.empty() && i-K >= max_deque.front()){
            max_deque.pop_front();
        }
        
        while(!max_deque.empty() && a[max_deque.back()] < a[i]){
            max_deque.pop_back();
        }

        max_deque.push_back(i);
    }

    cout<<a[max_deque.front()]<<"\n";


    return 0;

}
