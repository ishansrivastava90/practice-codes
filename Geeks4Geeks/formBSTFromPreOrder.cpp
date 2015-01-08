/*
 *  Forming a BST from a given preorder list of elements
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val){
    
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* formTree(int * a, int N){

    if( a == NULL)
        return NULL;

    stack<Node*> treeStack;

    int ind = 1;
    Node* root = newNode(a[0]);
    treeStack.push(root);

    while(ind < N){

        Node* node = NULL;
        if(a[ind] < (treeStack.top())->val){
            node = newNode(a[ind]);
            (treeStack.top())->left = node;
            treeStack.push(node);
        }
        else{
            while(!treeStack.empty() && a[ind] > (treeStack.top())->val){
                node = treeStack.top();  
                treeStack.pop();
            }
        
            node->right = newNode(a[ind]);
            treeStack.push(node->right);
        }
        ind++;

    }
    
    return root;

}

void printInOrder(Node* root){

    if( root == NULL)
        return;

    printInOrder(root->left);
    cout<<root->val<<"\n";
    printInOrder(root->right);

    return;
}

int main(){

    int N;
    int arr[20];
    
    scanf("%d",&N);

    for(int i =0;i<N;i++){
        scanf("%d",&arr[i]);
    }

    Node * root = formTree(arr,N);

    printInOrder(root);

    return 0;

}
