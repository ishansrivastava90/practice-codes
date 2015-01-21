#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct Node {
    int v;
    struct Node* next;
} Node;

void push(Node** head, int v){

    Node * node = (Node*)malloc(sizeof(Node));
    node->v=v;
    node->next=*head;

    *head = node;


}
bool isCyclic(Node* head){
    if(head == NULL || head->next == NULL)
        return false;

    Node* fast_ptr = head;
    Node* slow_ptr = head;

    while( fast_ptr != NULL && fast_ptr->next != NULL){

        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
        
        if(fast_ptr == slow_ptr)
            return true;
    }

    return false;

}
int main(){

    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;
    cout<<isCyclic(head);
    
    return 0;
}
