#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node {
	int v;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

Node* findInOrderSuccessor(Node* root, Node* node){
	if(root == NULL || node == NULL)
		return NULL;

	Node * res = NULL;
	if(root != node){
		res = findInOrderSuccessor(root->left, node);
		if( res!= NULL)
			return res;
		res = findInOrderSuccessor(root->right, node);
		return res;
	}

	Node * temp = node;
	if(node == node->parent->left){
		temp = temp->right;
		while(temp != NULL && temp->left != NULL)
			temp = temp->left;

		if( temp != NULL)
			return temp;
		else
			return node->parent;
	}
	else{
		temp = temp->right;
		while(temp!=NULL && temp->left != NULL)
			temp = temp->left;

		if( temp != NULL)
			return temp;
		else{
			temp = node;
			Node* curr_par = node->parent;
			while(curr_par != NULL && curr_par->left != temp){
				curr_par = curr_par->parent;
				temp = temp->parent;
			}

			return curr_par;
		}
	}

}

Node* newNode(int num,Node* parent)
{
    Node* temp = new Node;
    temp->v = num;
    temp->left = temp->right = NULL;
    temp->parent =parent;
    return temp;
}
// A utility function to insert a given key to BST
Node* insert(Node* root, Node* parent, int key)
{
    if (root == NULL)
       return newNode(key, parent);
    if (root->v > key)
       root->left = insert(root->left, root, key);
    else
       root->right = insert(root->right, root, key);
    return root;
}
 
// Driver program to test above functions
int main()
{
    Node* root = NULL;
    root = insert(root, NULL, 6);
    root = insert(root, NULL, -13);
    root = insert(root, NULL,14);
    root = insert(root, NULL,-8);
    root = insert(root, NULL,15);
    root = insert(root, NULL,13);
    root = insert(root, NULL,7);

    Node* succ = findInOrderSuccessor(root,root->right->right);
    if(succ == NULL)
    	cout<<"Rightmost Node\n";
    else
        cout<<succ->v<<"\n";

	return 0;
}