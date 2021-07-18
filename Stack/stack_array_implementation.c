#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE]; // array to hold the stack
int top = -1; // empty stack

void Push(int x){
    if(top == MAX_SIZE - 1){ // if push is called with no more space in the stack
        printf("Error: stack overflow\n");
        return;
    }
    
    A[++top] = x; // move the top of the stack one index up
}

void Pop(){
    if(top == -1){ // if there aren't any elements in the stack
        printf("Error: no elements to pop\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
} 

void Print(){
    int i;
    printf("Stack: ");
    for(i = 0; i <= top; i++){
        printf("%d ", A[i]);
    } 
    printf("\n");
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    Push(2);
    Push(4);
    Push(1);
    Print();
    printf("%d", Top());
}