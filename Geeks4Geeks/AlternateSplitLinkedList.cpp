#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef struct Node{
    int v;
    struct Node* next;
}Node;

void push(Node ** head, int val){

    Node* node = (Node*)malloc(sizeof(Node));
    node->v=val;
    node->next = *head;

    *head = node;

    return;
}

void alternateSplit(Node* head, Node **head2){

    if(head == NULL)
        return;

    Node* h1 = head;
    
    Node* h2 = NULL;

    while(h1 != NULL && h1->next != NULL){

        if(h2 == NULL){
            h2 = h1->next;
            *head2 = h2;
        }
        else{
            h2->next = h1->next;
            h2 = h2->next;
        }
        h1->next = h1->next->next;
        h1 = h1->next;
    }

    return;
}

void printList(Node* node){

    if(node == NULL)
        return;

    while(node!=NULL){
        cout<<node->v<<" -> ";
        node=node->next;
    }
    cout<<"\n";

    return;
}

int main(){
    Node* head = NULL;
    Node* a = NULL;

    /* Let us create a sorted linked list to test the functions
     *    Created linked list will be 0->1->2->3->4->5 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);                                    
    push(&head, 0);  

    printf("\n Original linked List:  ");
    printList(head); 

    alternateSplit(head, &a); 

    printf("\n Resultant Linked List 'a' ");
    printList(head);            

    printf("\n Resultant Linked List 'b' ");
    printList(a);            
                                             
    return 0;
}
