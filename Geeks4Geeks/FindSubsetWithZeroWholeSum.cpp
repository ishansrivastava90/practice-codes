#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int findSubset(int arr[], int N){
    
    if (arr == NULL || N== 0){
        cout<<"-1\n";
        return 0;
    }

    int half_sum = 0;
    int slen[500][N+1];
    for(int i =0;i<N;i++){

        half_sum += arr[i];
        slen[0][i]= 0;
    }
    slen[0][N] = 0;


    int index[500];
    int ind = 0;

    for(int i =1;i<= half_sum;i++){

        for(int j = 0;j<N;j++){

            if(j == 0){
                slen[i][j] = 0;
                if(i == arr[j])
                    slen[i][j] = 1;
            }
            else{

                int a = slen[i-arr[j] ][j-1];
                int b = slen[i][j-1];

                if( a > b ){
                    slen[i][j] = a + 1;
                    index[ind] = j;
                    ind++;
                }
                else
                    slen[i][j] = b;
            }
        }
    }

    for(int i =0;i< ind;i++)
        cout<<arr[index[i] ]<<" ";
    return slen[half_sum][N-1];

}


int main(){

    int N;
    scanf("%d",&N);

    int arr[100];

    for(int i =0;i< N;i++)
        scanf("%d",&arr[i]);

    cout<<"The length is "<< findSubset(arr, N);
    return 0;

}
