#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void minMax(int a[], int N, int* min, int* max){


	if(N == 0)
		return;

	int num_comp = 0;

	if(N == 1){
		*min = a[0];
		*max = a[1];
		return;
	}

	int p_min, p_max,ind;
	if(N%2 == 0){
		if(a[0] < a[1]){
			p_min = a[0];
			p_max = a[1];
			num_comp++;			
		}
		else{
			p_min = a[1];
			p_max = a[0];

		}
		ind =2;
	}
	else{
		p_min = p_max = a[0];
		ind = 1;
	}

	for(int i = ind; i<N-1;i+=2){

		if(a[i] < a[i+1]){
			if(p_min > a[i])
				p_min = a[i];
			if(p_max < a[i+1])
				p_max = a[i+1];
			num_comp +=3;
		}
		else {
			if(p_min > a[i+1])
				p_min = a[i+1];
			if(p_max < a[i])
				p_max = a[i];	
			num_comp +=3;
		}

	}

	*min = p_min;
	*max = p_max;
	cout<<"Num of comparisons "<<num_comp<<"\n";

	return;
}

int main() {
	
	//int arr[] = {4, 12, 43 , 456, 53, 27,783, 2, 7, 21, 91};
	int arr[] = {456, 91, 53, 27, 21, 14, 9, 5, 1 };

	int min = -1;
	int max = -1;

	minMax(arr, 9, &min, &max);

	cout<<"Min "<<min<<"\n";
	cout<<"Max "<<max<<"\n";

	return 0;


}
