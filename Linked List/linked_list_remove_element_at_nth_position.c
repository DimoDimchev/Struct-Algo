#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to the node 
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

void Delete(int position){ // delete element at position
    struct Node* temp = head;
    if (position == 1){
        head = temp->next; // head now points to the second node
        free(temp);
    } else{
       int i;
        for(i = 0; i < position - 2; i++){ // temp now points to (position - 1)th element
            temp = temp->next;
        }
        struct Node* temp1 = temp->next; // position-th element
        temp->next = temp1->next; // (position + 1)th element
        free(temp1); 
    }
} 

int main(){   
    head = NULL; // empty list

    // initialize list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    Print();

    int n;
    printf("Enter a position:\n");
    scanf("%d", &n);

    // delete element at position n
    Delete(n);
    Print();

    return 0;
}