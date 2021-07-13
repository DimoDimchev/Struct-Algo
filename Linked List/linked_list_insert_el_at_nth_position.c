#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data; // hold the data in the node 
    struct Node* next; // pointer to the node 
};

struct Node* head;

void Insert(int data, int index){
    int i;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    // IF ELEMENT IS FIRST IN THE LIST

    if(index == 1){ // if the element is inserted at the head, change the head to the element's address
        temp->next = head;
        head=temp;
        return;
    }

    // FOR ALL OTHER CASES

    struct Node* temp1 = head;
    for(i = 0; i < index - 2; i++){ // find the n-1 element
        temp1 = temp1->next;
    }
    temp->next = temp1->next; // break the link between n and n-1 element
    temp1->next = temp; // insert the new element and repair link
}

void Print(){
    struct Node* temp = head;
    while(temp != NULL){ // until there are untraversed elements in the list
        printf(" %d", temp->data); // print the element
        temp = temp->next; // move on to the next element
    }
    printf("\n");
}

int main(){
    head = NULL; // empty list

    Insert(2, 1); // List: 2
    Insert(3, 2); // List: 2, 3
    Insert(4, 1); // List: 4, 2, 3
    Insert(8, 2); // List: 4, 8, 2, 3
    Print();

    return 0;
}