#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to next node 
};

struct Node* head;

void Insert(int data){ // insert element at beginning of list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // create a new node
    temp->data = data; // asign x as the node's data
    temp->next = head; // link the element to the next element in the list or NULL if the element is the only element in the list
    head = temp; // make the current element's address the head node(beginning of list)
} 

void Print(){
    struct Node* temp = head;
    while(temp != NULL){ // until there are untraversed elements in the list
        printf(" %d", temp->data); // print the element
        temp = temp->next; // move on to the next element
    }
    printf("\n");
}

// REVERSE ALSO WORKS IN THE CASES WHERE THE LIST IS EMPTY OR HAS ONLY ONE NODE

void Reverse(){ // reverse the list by iterating through it and changing the links
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){   
    head = NULL; // empty list

    // initialize list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();

    // reverse list
    Reverse();
    Print();

    return 0;
}