
/****************************************************************************************
PROBLEM STATEMENT
-----------------
You are given a rooted tree with N nodes. Tree is rooted at node 1. 
Each node of the tree contains some value. Initially value of each node will be given.
You are given Q queries. Queries can be of two types, type U and type Q.

 Type U: This query is represented by U x v, which means that you
 have to add value v to node x.

 Type Q: This query is represented by Q x, which means that you
 have to output number of nodes in the subtree rooted at node x having value equal to zero.
 *****************************************************************************************/

//Solution in C++

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<list>

#define MAX 10000010
#define ll long long
#define llu long long unsigned
#define ld long

using namespace std;


typedef struct treeNode{
    vector<int> childNodes;
    ll weight;
    int numOfZeros;
    int parentNode;
}treeNode;

treeNode createNode(ll weight, int numOfZeros){
    treeNode *node = new treeNode();
    node->weight = weight;
    node->numOfZeros = numOfZeros;

    return *node;
}

void printTree(vector<treeNode > tree, int N){

    printf("The tree is as specified:\n");

    for(int node = 1;node<=N;node++){
        vector<int>::iterator iter;
        printf("Children for Node=%d with weight=%lld AND numOfZeros=%d\n",node,tree[node].weight, tree[node].numOfZeros);
        for(iter=(tree[node].childNodes).begin(); iter!=(tree[node].childNodes).end(); iter++){
            printf("Node = %d, Child_Val=%d\n",node, *iter);
        }
    }

    return;
}

int findNumOfZeros(vector<treeNode> &tree, int node){

    printf("ISHAN --\n");

    int numOfZeros = 0;
    if(tree[node].weight == 0)
        numOfZeros = 1;

    vector<int>::iterator iter;
    for(iter=(tree[node].childNodes).begin();iter!=(tree[node].childNodes).end();iter++){

        numOfZeros = numOfZeros + findNumOfZeros(tree, *iter);
    }
    tree[node].numOfZeros = numOfZeros;
    return numOfZeros;
}

int main(){

    int N, Q;
    int u;
    ll v,val;
    char type;
    int node;

    scanf("%d%d",&N, &Q);

    vector< treeNode > tree(N+1);

    tree[1].parentNode = -1;
    for(int i = 0;i<N-1;i++){
        scanf("%d%lld",&u,&v);

        (tree[u].childNodes).push_back(v);
        tree[v].parentNode = u; 
    }

    printTree(tree,N);

    for(int i=1;i<=N;i++){
        scanf("%lld",&tree[i].weight);
        tree[i].numOfZeros = -1;
    }

    printTree(tree,N);


    for(int i=0;i<Q;i++){
        getchar();
        scanf("%c",&type);
        printf("Type =%c\n",type);

        if(type =='U'){
            scanf("%d%lld",&node,&val);
            tree[node].weight = tree[node].weight + val;


            if(tree[node].weight - val == 0){
                tree[node].numOfZeros--;
                int parent = tree[node].parentNode;
                while(parent != -1){
                    tree[parent].numOfZeros--;
                    parent = tree[parent].parentNode;
                }

            }

            printTree(tree,N);

        }
        else{
            scanf("%d",&node);
            if(tree[node].numOfZeros>=0)
                printf("%d\n",tree[node].numOfZeros);
            else{

                printf("%d\n",findNumOfZeros(tree, node));
            }

        }
    }

    return 0;
}

