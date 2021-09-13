#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node{
	int v;
	struct Node* left;
	struct Node* right;
} Node;

void printPath(int path[], int end, int start){
	for(int i = start; i<=end; i++)
		cout<<path[i]<<"-";
	cout<<"\n";
}

void findAllPathSum(Node* root, int path[],  int level, int sum){
	if(root == NULL)
		return;

	path[level] = root->v;
	int pathSum =0;
	for(int i = level;i>=0;i--){
		pathSum += path[i];
		if(pathSum == sum)
			printPath(path,level,i);
	}

	findAllPathSum(root->left, path, level+1, sum);
	findAllPathSum(root->right, path, level+1, sum);

	return;

}

Node* newNode(int num,Node* parent)
{
    Node* temp = new Node;
    temp->v = num;
    temp->left = temp->right = NULL;
    
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

    int path[30];
    findAllPathSum(root,path,0,20);

	return 0;
}