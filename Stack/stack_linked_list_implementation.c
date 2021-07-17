#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to the node 
};

struct Node* top = NULL;

void Push(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // create a new node
    temp->data = x; // asign x as the node's data
    temp->next = top; // link the element to the next element in the stack or NULL if the element is the only element in the list
    top = temp; // make the current element's address the head node(beginning of stack)
}

void Pop(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // create a new node
    if(top == NULL) return;
    temp = top;
    top = top->next;
    free(temp);
}

int Top(){
    if(top == NULL){
        printf("Error: no elements in stack\n");
        return 0;
    }
    return top->data;
}

void Print(){
    struct Node* temp = top;
    printf("List is: ");
    while(temp != NULL){ // until there are untraversed elements in the stack
        printf(" %d", temp->data); // print the element
        temp = temp->next; // move on to the next element
    }
    printf("\n");
}

int main(){
    Push(1);
    Push(5);
    Push(3);
    Print();
    printf("%d", Top());

    return 0;
}