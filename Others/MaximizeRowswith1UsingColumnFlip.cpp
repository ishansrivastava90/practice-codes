#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>

#define MIN_INT -100000

using namespace std;

string computeHash(int row[], int c){

	string st = "";
	for(int i =0;i<c;i++)
		st = st + std::to_string(row[i]);

	return st;
}

int maximizeMat(int m[][50], int r, int c){

	if( r == 0 || c == 0 )
		return -1;

	map<string, int> uniqueRows;
	int max_val = MIN_INT;
	for(int i = 0; i < r; i++){

		string hashKey = computeHash(m[i],c);
		if(uniqueRows.find(hashKey) != uniqueRows.end())
			uniqueRows[hashKey] += 1;
		else
			uniqueRows[hashKey] = 1;

		if(uniqueRows[hashKey] > max_val)
			max_val = uniqueRows[hashKey];
	}
	
	return max_val;

}
	
int main(){

	int R, C;
	scanf("%d%d",&R,&C);

	int mat[50][50];
	for(int i =0;i<R;i++){
		for(int j =0;j<C;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	cout<<maximizeMat(mat, R,C);

	return 0;
}