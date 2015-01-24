#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stdio.h>

using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int data)
{
    Node* node = (Node*)
        malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

bool isFull(Node* node){ 
    if(node == NULL)
        return false;

    if(node->right != NULL && node->left != NULL)
        return true;

    return false;
}

bool isLeaf(Node* node){

   if(node == NULL)
       return false;

   if(node->right == NULL && node->left == NULL)
       return true;

   return false;
}

bool isComplete(Node* root){

    if( root == NULL)
        return true;

    int prev_level = 0, curr_level = 0;
    queue<Node*> q;

    q.push(root);
    bool checkLeaf = false;
    if(!isFull(root))
        checkLeaf = true;

    while(!q.empty()){
        
        Node * n = q.front();
        q.pop(); 
        if(n->left == NULL && n->right != NULL)
            return false;
        
        if(n->left != NULL){
            if(checkLeaf && !isLeaf(n->left))
                return false;

            q.push(n->left);
            if(!isFull(n->left))
                checkLeaf =true;
        }
        if(n->right != NULL){
            if(checkLeaf && !isLeaf(n->right))
                return false;

            q.push(n->right);
            if(!isFull(n->right))
                checkLeaf =true;


        }
    }

    return true;
}
    


int main(){
    Node *root  = newNode(1);

    root->left         = newNode(2);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(5);
    root->right->right = newNode(6);

    if ( isComplete(root) == true )
        printf ("Complete Binary Tree");
    else
        printf ("NOT Complete Binary Tree");

    return 0;
}
