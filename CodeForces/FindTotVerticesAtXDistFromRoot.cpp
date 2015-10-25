#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

typedef long long ll 
using namespace std;

long findCount(int N, ll X, ll *dist){
	if(N == 0 )
		return 0;

	ll totVert = 1;
	queue<ll> nqueue;
	nqueue.push(0);

	while(!nqueue.empty()){

		long curr_root = nqueue.front();
		nqueue.pop();
		for(int i=0;i<N;i++){
			if(curr_root + dist[i] <= X){
				totVert = (totVert+1)%1000000007;
				nqueue.push(curr_root + dist[i]);
			}
		}

	}
	return totVert;
}
int main(){

	int N;
	long X;
	scanf("%d%ld",&N,&X);

	long *dist = (long*)malloc(sizeof(long)*N);
	for(int i=0;i<N;i++)
		scanf("%ld",&dist[i]);

	cout<< findCount(N,X,dist)<<"\n";
	return 0;
}