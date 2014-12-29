/*****************************************************************************************************************
PROBLEM STATEMENT -  Root of the problem

Chef has a binary tree. The binary tree consists of 1 or more nodes. Each node has a unique integer id. 
Each node has up to 2 children, which are identified by their ids, and each node is the child of at most 1 other node.
 A node X is considered to be an ancestor of node Y if node Y is a child of node X or if there is some node 
Z for which X is an ancestor of Z and Y is a child of Z. No node is an ancestor of itself. 
A special node called the root node is an ancestor of all other nodes. Chef has forgotten which node of his tree
 is the root, and wants you to help him to figure it out. Unfortunately, Chef's knowledge of the tree is incomplete. 
He does not remember the ids of the children of each node, but only remembers the sum of the ids of the children of each node.
************************************************************************************************************************/

#include <cstdio>
#include <string.h>
#include <iostream>

int main(){
	int T, N, id, sum, root;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		root=0;
		while(N--){
			scanf("%d%d", &id, &sum);
			root+=id-sum;
		}
		printf("%d\n", root);
	}
	return 0;
}
