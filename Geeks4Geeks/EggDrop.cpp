#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

using namespace std;
int max(int a, int b) { return (a > b)? a: b; }

int findMinDrops(int eggs, int floors){

    if( eggs == 0  || floors == 0)
        return 0;

    int drops[eggs+1][floors+1];

    for(int i = 0; i <= eggs; i++){
        drops[i][1] = 1;
        drops[i][0] = 0;
    }

    for(int i = 0;i<= floors; i++)
        drops[1][i] = i;

    for(int i = 2;i<= eggs; i++){
        for(int j = 2;j<= floors; j++){
            drops[i][j] = INT_MAX;

            for(int x = 1; x<=j ; x++){
                int max_val = max(drops[i-1][x-1], drops[i][j-x]);
                if( drops[i][j] > ( 1 +  max_val))
                    drops[i][j] = 1 + max_val;
            }
        }
    }

    return drops[eggs][floors];       


}

int main(){
    
    int eggs = 2, floors = 36;
    cout<< findMinDrops(eggs, floors)<<"\n";
    return 0;

}
