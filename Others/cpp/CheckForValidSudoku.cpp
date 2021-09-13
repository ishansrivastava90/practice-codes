#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

bool isValidNum(int num, int limit){
	if(num < 1 || num > limit)
		return false;
	return true;
}

bool isValidSudoku(int sudokuMat[][50],int N){

	if( sudokuMat == NULL || N == 0)
		return false;

	bool checkRows[N+1];
	bool checkCols[N+1];
	bool checkCube[N+1];
	for(int i =1 ; i <= N; i++){
		for(int j = 1;j<= N; j++){
			checkRows[j] = false;
			checkCols[j] = false;
		}
		for(int j = 1; j <= N; j++){

			if(!isValidNum(sudokuMat[i][j], N)){
				cout<< "Not a valid Num";
				return false;
			}

			if( checkRows[sudokuMat[i][j]]){
				cout<< "Failing the Row Check";
				return false;
			}
			checkRows[sudokuMat[i][j]] = true;

			if( checkCols[sudokuMat[j][i]]){
				cout<< "Failing the Col Check";
				return false;
			}
			checkCols[sudokuMat[j][i]] = true;
		}
	}

	/* Checking for the individual sub- cubes*/
	int sqN = sqrt(N);
	for(int k = 1;k <= sqN; k++){
		for(int kk = 1; kk <= sqN; kk++){
			for(int kkk = 1;kkk<= N; kkk++){
				checkCube[kkk] = false;			
			}	
			for(int i = sqN*(k-1)+1; i<= sqN*k; i++){
				for(int j = sqN*(k-1)+1; j<= sqN*k; j++){
					if (checkCube[sudokuMat[i][j]]){
						cout<< "Failing the Cube Check";
						return false;
					}
					checkCube[sudokuMat[i][j]] = true;
				}
			}
		}		
	}

	return true;
}
int main(){

	int N;
	scanf("%d", &N);

	int sudokuMat[50][50];
	for(int i=1; i<=N; i++){
		for (int j= 1; j<=N; j++){
			scanf("%d",&sudokuMat[i][j]);
		}
	}
	cout<< isValidSudoku(sudokuMat, N);
	return 0;
} 