#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node {
    int v;
    struct Node* next;
} Node;

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node =
        (Node*) malloc(sizeof(Node));

    /* put in the data  */
    new_node->v  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);     

    /* move the head to point to the new
     * node */
    (*head_ref)    = new_node;
}

void removeDuplicates(Node* node){

    if(node == NULL)
        return;

    while(node!= NULL){

        while(node->next != NULL && node->next->v == node->v){
            Node* temp = node->next;
            node->next = node->next->next;
            free(temp);
        }

        node= node->next;
    }
    return;
}

void printList(Node* node){
    if(node == NULL)
        return;

     while(node != NULL){
         cout<<node->v<<" ";
         node = node->next;
     }
     cout<<"\n";
     return;

}

int main(){

    Node* head = NULL;

    /* Let us create a sorted linked list to test the functions
     *    Created linked list will be 11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);  
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);                                    

    printf("\n Linked list before duplicate removal  ");
    printList(head); 

    /* Remove duplicates from linked list */
    removeDuplicates(head); 

    printf("\n Linked list after duplicate removal ");         
    printList(head);            

    return 0;
}
