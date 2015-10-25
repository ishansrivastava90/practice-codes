#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct Node{
	int v;
	struct Node* right;
	struct Node* left;
} Node;

Node* createNode(int v){
	Node * node = (Node*)malloc(sizeof(Node));
	node->v= v;
	node->right = NULL;
	node->left = NULL;

	return node;
}
vector<Node*> convertToListLevelOrder(Node* root){

	vector<Node*> llvector;
	if( root == NULL)
		return llvector;
	

	queue<Node*> q;
	q.push(root);
	
	int numOfNodesInQ = 1;
	int numOfNodesToPop = 1;

	while(!q.empty()){

		numOfNodesInQ = 0;
		Node * head = NULL;
		Node *prev_node = NULL;
		Node* node = NULL;

		for(int i=1;i<=numOfNodesToPop;i++){
			node = q.front();
			q.pop();
			
			if(node->left != NULL){
				q.push(node->left);
				numOfNodesInQ++;
			}
			if(node->right != NULL){
				q.push(node->right);
				numOfNodesInQ++;
			}

			node->left = NULL;
			node->right = NULL;
				
			if(head == NULL){
				head = node;			
			}
			else{				
				prev_node->right = node;
			}
			prev_node = node;

		}
		numOfNodesToPop = numOfNodesInQ;
		llvector.push_back(head);
	}

	return llvector;


}
void printLinkedList(Node* head){
	if(head == NULL)
		return;

	cout<<head->v<<"->";
	printLinkedList(head->right);

	return;
}
int main(){

	Node * root = createNode(7);
	root->left = createNode(3);
	root->right = createNode(15);
	root->left->left = createNode(1);
	root->left->right = createNode(6);	
	root->right->right = createNode(21);

	root->left->left->right = createNode(2);
	root->right->right->left = createNode(16);
	root->right->right->right = createNode(24);
	
	cout<<"Tree formed\n";

	vector<Node*>::iterator it;
	vector<Node*> v = convertToListLevelOrder(root);
	cout<<"Printing all the lists\n";
	for(it=v.begin();it!=v.end();it++){
		printLinkedList(*it);
		cout<<"\n"
;	}
	return 0;
}