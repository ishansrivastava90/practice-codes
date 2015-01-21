#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node{
    int v;
    struct Node* next;
}Node;

void push(Node** head, int v){
    Node* node = (Node*)malloc(sizeof(Node));
    node->v=v;
    node->next =NULL;

    node->next = *head;
    *head = node;
}

Node* reverseAlternate(Node**head, Node *currNode, int K, bool flag,int count){
    
    if(currNode->next == NULL ){
        *head = currNode;
        return currNode;
    }
        
    bool newflag = flag;
    if(count == K){
        count = 0;
        if(newflag)
            newflag = false;
        else
            newflag = true;
    }
    Node* prevNode = reverseAlternate(head,currNode->next, K, newflag,count+1);
    if(flag != newflag){
        currNode->next = *head;
        *head = currNode;
        return currNode;
//        prevNode = *head;
    }

    if(flag){
        Node* temp = prevNode->next;
        prevNode->next = currNode;
        currNode->next = temp;

    }
    else{
        currNode->next = prevNode;
        *head = currNode;
    }

    return currNode;

}
void printList(Node *node)
{
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->v);
        node = node->next;
        count++;
    }
}    

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    Node* head = NULL;

    // create a list 1->2->3->4->5...... ->20
    for(int i = 20; i > 0; i--)
        push(&head, i);

    printf("\n Given linked list \n");
    printList(head);
    reverseAlternate(&head,head,3,true,1);

    printf("\n Modified Linked list \n");
    printList(head);


    return 0;
}
