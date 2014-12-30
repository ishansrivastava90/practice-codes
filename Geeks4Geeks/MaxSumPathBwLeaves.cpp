#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define MIN_INT -1000000

using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

// Utility function to allocate memory for a new node
struct Node* newNode(int data)
{
    struct Node* node = new(struct Node);
    node->data = data;
    node->left = node->right = NULL;
   return (node);
}
int max(int a , int b){
    return a>b?a:b;
}

int maxPathSum(Node* node, int &maxSum){

    if(node == NULL)
        return MIN_INT;
    if(node->left == NULL && node->right == NULL)
        return node->data;

    int pathSumLeft = maxPathSum(node->left,maxSum);
    int pathSumRight = maxPathSum(node->right,maxSum);

    if( maxSum < node->data+ pathSumLeft+pathSumRight)
        maxSum = node->data+pathSumLeft+pathSumRight;

    return node->data + max(pathSumLeft,pathSumRight);

    
}


int main(){

    /*struct Node *root = newNode(-15);
    root->left = newNode(5);
    root->right = newNode(6);
    root->left->left = newNode(-8);
    root->left->right = newNode(1);
    root->left->left->left = newNode(2);
    root->left->left->right = newNode(6);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->right->right= newNode(0);
    root->right->right->right->left= newNode(4);
    root->right->right->right->right= newNode(-1);
    root->right->right->right->right->left= newNode(10);*/
    struct Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(-3);
    root->left->left = newNode(-4);
    root->left->right = newNode(-5);
    root->left->left->left = newNode(-8);
    root->right->left = newNode(-6);
    root->right->right = newNode(-7);
    int maxSum = MIN_INT;
    int ret = maxPathSum(root,maxSum);
    cout << "Max pathSum of the given binary tree is " << maxSum;
    return 0;
}

