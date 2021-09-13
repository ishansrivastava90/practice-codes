#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>

/* The code finds if a number exists in the specified range of the
/  elements of a given window.*/

using namespace std;


bool isDuplicateInWindow(int arr[], int N, int k, int range){ 
	if ( arr == NULL || N == 0)
		return false;

	map<int, int> windowMap;

	for(int i =0; i< N; i++){
		if( i > k){
			for(int j = arr[i - k -1] - range ;j <= arr[i-k-1]+range;j++){
				windowMap[j]--;
			}
		}

		for(int j = arr[i] - range ;j <= arr[i]+range;j++){

			if(windowMap.find(j) != windowMap.end() && windowMap[j] > 0 )
				return true;

			if(windowMap.find(j) == windowMap.end()){
				windowMap[j] = 1;
			}
			else{
				windowMap[j]++;	
			}

		}
		
	}
	return false;
}

int main(){

	int N,k;
	scanf("%d%d",&N,&k);
	int arr[50];
	for(int i =0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	cout<<isDuplicateInWindow(arr, N, k, 2);
	return 0;
}