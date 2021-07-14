#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GenerateNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// insert node at beginning of list
void InsertAtHead(int x){
   struct Node* temp = GenerateNode(x);
   if(head == NULL){
       head = temp;
       return;
   }
   head->prev = temp;
   temp->next = head;
   head = temp;
}

// insert node at end of list
void InsertAtTail(int x){
    struct Node* temp = GenerateNode(x);
    if(head == NULL){
        head = temp;
        return;
    }
    struct Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = NULL;
    temp->prev = temp1;
}

void Print(){
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint(){
    struct Node* temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    head = NULL;

    InsertAtHead(2);
    InsertAtHead(4);
    InsertAtHead(6);
    InsertAtTail(8);

    Print();
    ReversePrint();
}