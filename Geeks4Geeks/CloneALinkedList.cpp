#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<map>

using namespace std;

typedef struct Node {
    int v;
    struct Node* next;
    struct Node* rnd;
} Node;

class LinkedList{

    private:

        Node* ll;
        int len;
    
        Node* createNewNode(int val){

            Node* node = (Node*) malloc(sizeof(Node));
            node->v = val;
            node->next = NULL;

            return node;
        }

    public:

         LinkedList(int arr[], int N){

             if(arr==NULL || N ==0){
                 this->ll = NULL;
                 this->len = 0;
             }

             this->ll = NULL;
             this->len = N;

             Node *tempHead= NULL;

             for(int i =0;i<N;i++){

                 if( tempHead == NULL){
                     tempHead = createNewNode(arr[i]);
                     this->ll= tempHead;
                 }
                 else{
                     tempHead->next = createNewNode(arr[i]);
                     tempHead = tempHead->next;
                 }
             }

         }


         void addRandomPointers(){
             Node* head = this->ll;

             if(head == NULL)
                 return;

             Node* it = head;
             while(it!=NULL){
                int loc = rand()%this->len + 1;

                 Node* s = head;
                 int c = 1;
                 while(c < loc){
                     s = s->next;
                     c++;
                 }

                 it->rnd = s;            
                 it = it->next;
             }

         }

         void print(){
             Node* head = this->ll;
             while(head != NULL){
                 cout<<head->v<<" -> ";
                 head = head->next;
             }
             cout<<"\n";
         }

         void printWithRndPointers(){

             Node* h = this->ll;
             cout<<"Node Values:\n";
             while(h != NULL){
                 cout<<h->v<<" -> ";
                 h = h->next;
             }
             cout<<"\nRandom Pointers:\n";
             h = this->ll;
             while(h != NULL){
                 cout<<h->rnd->v<<" -> ";
                 h = h->next;
             }
             cout<<"\n";
         }

         Node* clone(){

             if(this->ll == NULL || this->len == 0)
                 return NULL;

              Node* head =NULL,*clone_node =NULL;
              Node* node = this->ll;
              
              head = createNewNode(node->v);
              clone_node = head;
              
              multimap<Node*, Node*> randMap;
              randMap.insert(pair<Node*,Node*>(node->rnd,clone_node));

              node = node->next;

              while(node != NULL){
                  clone_node->next = createNewNode(node->v);

                  randMap.insert(pair<Node*,Node*>(node->rnd,clone_node->next));
                  clone_node = clone_node->next;
                  node = node->next;               

              }

              node = this->ll;
              clone_node = head;
              map<Node*, Node*>::iterator it;
              while( node != NULL){
                  Node* pNode;
                  it = randMap.find(node);
                  while(it != randMap.end()){
                      cout<<"ISHAN\n";
                      pNode = it->second;
                      pNode->rnd = clone_node;
                      randMap.erase(it);
                      it = randMap.find(node);
                      
                  }

                  node = node->next;
                  clone_node = clone_node->next;

              }

              return head;

         }

};

int main(){

    int N;
    scanf("%d",&N);

    int arr[100];
    for(int i =0;i<N;i++)
        scanf("%d",&arr[i]);

    //Creating a linked List
    LinkedList list(arr,N);
    list.print();

    //Adding Random Pointers
    list.addRandomPointers();
    list.printWithRndPointers();

    Node* clonelist = list.clone();

    Node* h = clonelist;
    cout<<"Node Values:\n";
    while(h != NULL){
        cout<<h->v<<" -> ";
        h = h->next;
    }
    cout<<"\nRandom Pointers:\n";
    h = clonelist;
    while(h != NULL){
        if(h->rnd != NULL)
            cout<<h->rnd->v<<" -> ";
        h = h->next;


    }
    return 0;
}

