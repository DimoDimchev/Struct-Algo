#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to the node 
};

struct Node* head;

void Insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // create a new node
    temp->data = x; // asign x as the node's data
    temp->next = head; // link the element to the next element in the list or NULL if the element is the only element in the list
    head = temp; // make the current element's address the head node(beginning of list)
}

void Print(){
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL){ // until there are untraversed elements in the list
        printf(" %d", temp->data); // print the element
        temp = temp->next; // move on to the next element
    }
    printf("\n");
}

int main(){
    head = NULL; // empty list

    printf("How many numbers will the list consist of?\n");
    int n,i, x;
    scanf("%d", &n);

    for(i = 0; i < n; i++ ){
        printf("Enter the number for index %d\n", i);
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    return 0;
}