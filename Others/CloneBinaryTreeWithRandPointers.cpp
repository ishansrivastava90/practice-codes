#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int v;
	struct Node* left, *right;
	struct Node* rnd;
} Node;

Node* createNode(int v){
	Node* node = (Node*)malloc(sizeof(Node));
	node->v = v;
	node->left= node->right = node->rnd = NULL;

	return node;
}
Node* cloneTree(Node* root){
	if(root == NULL)
		return root;

	Node* node = createNode(root->v);
	Node* left = root->left;
	root->left = node;
	node->left = cloneTree(left);
	root->right = cloneTree(root->right);

	return root;
}

void setRandomPointers(Node* root){
	if(root == NULL)
		return;

	if(root->left != NULL){
		root->left->rnd;
		if(root->rnd != NULL)		
			root->left->rnd = root->rnd->left;
	}
	setRandomPointers(root->left);
	setRandomPointers(root->right);
	return;

}

Node* restoreTree(Node * root){
	if(root == NULL)
		return root;

	Node * cloneNode = root->left;
	root->left = root->left->left;

	clonedNode->left = restoreTree(root->left);
	clonedNode->right = restoreTree(root->right);

	return clonedNode;
}
Node  * cloneBinaryTree(Node* root){

	if(root == NULL)
		return root;

	Node* tempTree = createClone(root);
	tempTree = setRandomPointers(tempTree);
	Node* clone = restoreTree(tempTree);

	return clone;
}
int main(){

	/* Driver Program to test*/
	return 0;
}