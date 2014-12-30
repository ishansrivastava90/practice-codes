#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node{
    struct Node* left;
    struct Node* right;
    int val;
} Node;


Node* createNode(int val){

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void addNode(Node* node, int val, int direction){

    if(node == NULL){
        node = createNode(val);
    }
    if(direction == 0){
        if(node->left == NULL){
            node->left = createNode(val);
        }
        else{
            direction = rand()%2;
            addNode(node->left, val, direction);
        }
    }
    else{
        if(node->right == NULL){
            node->right = createNode(val);
        }
        else{
            direction = rand()%2;
            addNode(node->right, val, direction);
        }
    }

    return;
}

void printTree(Node* root){
    if( root == NULL)
        return;
    printf("Going left\n ");
    printTree(root->left);
    printf("Node - %d\n",root->val);
    printf("Going right\n ");
    printTree(root->right);
    return;
}

void findDiagonalSum(Node* node, int diagonalSum[100], int diagInd){

    if(node == NULL)
        return;
    diagonalSum[diagInd] += node->val;

    findDiagonalSum(node->right, diagonalSum, diagInd);
    findDiagonalSum(node->left, diagonalSum, diagInd+1);

    return;
}


int main(){
    int num;
    scanf("%d",&num);

    int direction,val;
    Node *root = NULL;
    
    for(int i=0;i<num;i++){
        scanf("%d",&val);
        if(root == NULL)
            root = createNode(val);
        else{
            direction = rand()%2;
            addNode(root,val,direction);
        }
    }

    int diagonalSum[100];

    memset(diagonalSum,0,100);
   
    printTree(root);
    findDiagonalSum(root, diagonalSum, 0);

    int ind = 0;

    while(diagonalSum[ind] != 0 )
    {
        printf("%d\n",diagonalSum[ind]);
        ind++;
    }

    return 0;
}
