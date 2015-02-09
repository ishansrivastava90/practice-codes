#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
typedef struct ret{
	int v;
	int ind;
} ret;

ret findlocal(int arr[],int N){

	ret res;
	if(N == 0){
		res.v = -1;
		res.ind = -1;
		return res;
	}
	
	if(N == 1){
		res.v = arr[0];
		res.ind = 0;
		return res;
	}

	int begin = 0;
	int end = N-1;
	int mid;

	while(begin < end -  1){
		mid = (begin + end)/2;

		//Case 1
		if(arr[mid] < arr[begin] && arr[mid] > arr[end]){
			begin = mid+1;
		}
		//Case 2
		else if(arr[mid] > arr[begin] && arr[mid] < arr[end]){
			end = mid - 1;
		}
		// Case 3
		else if(arr[mid] < arr[begin] && arr[mid] < arr[end]){
			if(mid != N-1 && arr[mid] > arr[mid+1])
				begin = mid+1;
			else if(mid != 0 && arr[mid] > arr[mid-1])
				end = mid - 1;
			else{
				res.v = arr[mid];
				res.ind = mid;
				return res;
			}
				
		}
		else if(arr[mid] > arr[begin] && arr[mid] > arr[end]){
			end = mid - 1;
		}
	}
	if(begin != end){

		res.v = arr[begin] > arr[end]?arr[end]:arr[begin];
		res.ind = arr[begin] > arr[end]?end:begin;
	}
	else if(begin == 0 && arr[begin] < arr[begin+1]){
		res.v = arr[begin];
		res.ind = begin;		
	}
	else if(begin == N-1 && arr[begin] < arr[begin-1]){
		res.v = arr[begin];
		res.ind = begin;		
	}	
	else if(begin != 0 && begin != N-1 && arr[begin] < arr[begin-1] && arr[begin] < arr[begin+1]){
		res.v = arr[begin];
		res.ind = begin;
	}

	return res;
}

int main(){

	int arr[] = {5,6,7,2,1,4,3};
	ret res = findlocal(arr,7);
	cout<<res.v<<" "<<res.ind<<"\n";
	return 0;
}