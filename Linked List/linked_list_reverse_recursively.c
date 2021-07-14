#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to next node 
};

struct Node* head;

void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // create a new node
    temp->data = x; // asign x as the node's data
    temp->next = head; // link the element to the next element in the list or NULL if the element is the only element in the list
    head = temp; // make the current element's address the head node(beginning of list)
}

void Print(struct Node* head){
    if(head == NULL){ // base case
        printf("\n");
        return; 
    }

    printf("%d ", head->data);
    Print(head->next); // recursive call
}

// REVERSE LIST
void Reverse(struct Node* p){
    if(p->next == NULL){ // base case
        head = p;
        return; 
    }

    Reverse(p->next); // recursive call
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main(){   
    head = NULL; // empty list

    // initialize list
    Insert(2);
    Insert(5);
    Insert(4);
    Insert(6);
    Print(head);

    printf("\n");
    
    Reverse(head);
    Print(head);
}