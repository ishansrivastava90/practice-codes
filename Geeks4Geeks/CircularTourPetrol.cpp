#include<iostream>
#include<stdlib.h>
#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct station {
    int cap;
    int dist;
} station;

int findStation(station st[], int N){

    if(N == 0)
        return -1;

    int ind = 0;
    int rem_petrol = 0;
    int start_st = 0;
    int hops = 0;
    while(hops < N ){

        if(rem_petrol < 0){
            start_st = ind;
            rem_petrol = st[ind].cap - st[ind].dist;
            hops = 0;
        }
        else{
            rem_petrol += st[ind].cap - st[ind].dist;
            hops++;
        }
        ind = (ind+1)%N;
    }
    return start_st;       
            
}
int main(){
    
    int N;
    scanf("%d",&N);

    station st[20];
    for(int i =0; i< N; i++){
        scanf("%d%d",&st[i].cap, &st[i].dist);
    }

    cout<<findStation(st,N);
    return 0;
}
