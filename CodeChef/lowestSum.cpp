#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
using namespace std;

int compare(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}   

int binsearch(int *b, int left, int right,int val){

    if(left> right){
        if(b[right] > val)
            return right;
        else
            return left;
    }

    if(left == right)
    {
        if(b[left]>= val)
            return left;
        else
            return left+1;
    }

    int mid = (left+right)/2;
    int res;

    if(b[mid] == val)
        return mid;

    if(b[mid] > val){
        res=binsearch(b,left, mid-1,val);
    }
    else if(b[mid]<val){
        res= binsearch(b,mid+1,right,val); 
    }

    return res;

}

int findNumOfPairs(int *a, int * b, int sum,int ind){

    int numOfPairs = 0;
    cout<<sum<<"\n";
    for(int i =0;i<=ind;i++){
        if(a[i] >= sum)
            break;
        cout<<binsearch(b,0,ind,sum - a[i])<<"\n"    ;
        numOfPairs += binsearch(b,0,ind, sum - a[i]);
    }

    return numOfPairs;
}
int main(){

    int K;
    scanf("%d",&K);

    int *a = new int[100];
    int *b = new int[100];

    for(int i=0;i<K;i++){
        scanf("%d",&a[i]);
        scanf("%d",&b[i]);

    }

    int Q;
    scanf("%d",&Q);

    qsort(a,K, sizeof(int),compare);

    for(int i = 0;i<K;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(int i = 0;i<K;i++)
        cout<<b[i]<<" ";
    cout<<"\n";

    qsort(b,K, sizeof(int), compare);

    int q;
    int sum;
    while(Q--){

        scanf("%d",&q);

        int left = a[0]+b[0];
        int ind;
        if(q > K)
            ind = K-1;
        else
            ind = q-1;
        int right = a[ind]+b[ind];

        while(left<=right){
            cout<<"left="<<left<<" "<<"right="<<right<<"\n";

            int mid = (left + right)/2;

            int numOfPairs = findNumOfPairs(a,b,mid,ind);

            cout<<"Pairs = "<<numOfPairs<<"\n";

            if(numOfPairs == q-1){
                sum = mid;
                break;
            }


            if(numOfPairs > q-1)
                right = mid - 1;
             else
                 left = mid +1;
        }

    }

    cout<<sum;

}
