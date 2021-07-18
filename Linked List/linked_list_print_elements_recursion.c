#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to next node 
};

struct Node* Insert(struct Node* head, int data){ // insert element at end of list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data; 
    temp->next = NULL; 
    if(head == NULL) head = temp; 
    else{
        struct Node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
} 

// PRINT ALL ELEMENTS RECURSIVELY
void Print(struct Node* head){
    if(head == NULL){ // base case
        printf("\n");
        return; 
    }

    printf("%d ", head->data);
    Print(head->next); // recursive call
}

// PRINT ALL ELEMENTS RECURSIVELY IN REVERSE ORDER
void ReversePrint(struct Node* head){
    if(head == NULL){ // base case
        return; 
    }

    ReversePrint(head->next); // recursive call
    printf("%d ", head->data);
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){   
    struct Node* head = NULL; // empty list

    // initialize list
    head = Insert(head, 2);
    head = Insert(head, 5);
    head = Insert(head, 4);
    head = Insert(head, 6);
  
    Print(head);
    ReversePrint(head);
}