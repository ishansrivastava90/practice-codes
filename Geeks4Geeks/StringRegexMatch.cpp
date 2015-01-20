#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

bool match(char *S1, char *S2){

    if(S1 == NULL || S2 == NULL)
        return false;

    if(strlen(S1) == 0 && strlen(S2) == 0)
        return true;

    bool matchTab[100][100];

    for(int i = 1;i <= strlen(S1); i++)
        matchTab[i][0] = false;
    for(int i = 1;i <= strlen(S2); i++){
        if(i == 1 && S2[i-1] == '*')
            matchTab[0][i] = true;
        else
            matchTab[0][i] = false;
    }

    matchTab[0][0] = true;

    for(int i=1;i<=strlen(S1);i++){
        for(int j =1;j<=strlen(S2);j++){
            
            if(S1[i-1] == S2[j-1] || S2[j-1] == '?')
                matchTab[i][j] = matchTab[i-1][j-1];

            else if(S2[j-1] == '*')
                matchTab[i][j] = matchTab[i-1][j] || matchTab[i][j-1];

        }

    }

    return matchTab[strlen(S1)][strlen(S2)];    


}
int main(){

    char S1[100], S2[100];
    scanf("%s",S1);
    scanf("%s",S2);
    

    cout<<"String1:"<<S1<<"--\n";
    cout<<"String2:"<<S2<<"--\n";


    cout<< match(S1, S2);

    return 0;
}
