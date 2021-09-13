#include<stdio.h>
#include<string.h>
#include<malloc.h>

void combineWords( char * seed, bool * used, char* target, int ind){
    int len = strlen(seed);
    if(ind == len){
        target[ind] ='\0';
        printf("Combination : %s\n",target);
    }

    for(int i =0; i<len;i++){
        if(used[i] == 1)
            continue;

        target[ind] = seed[i];
        used[i] = 1;

        combineWords(seed, used, target, ind+1);
        used[i] = 0;
    }

    return;
}

int main(){
   

    char* seedWord = (char*)malloc(sizeof(char)*10);
    scanf("%s",seedWord);

    int len = strlen(seedWord);
    bool *used = (bool*)calloc(sizeof(bool),len);
    char* targetWord = (char*)malloc(sizeof(char)*len);

    combineWords(seedWord ,used, targetWord, 0);

    return 0;
}
