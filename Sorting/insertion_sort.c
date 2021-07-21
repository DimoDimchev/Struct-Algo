#include<stdlib.h>
#include<stdio.h>

void InsertionSort(int A[], int n){ // pass an array and the number of elements
    int i, j;
    for(i = 1; i < n; i++){ // traverse the array
        int value = A[i];
        j = i;
        while(j > 0 && A[j - 1] > value){ 
            A[j] = A[j - 1];
            j--;
        }
        A[j] = value;
    }
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {1, 4, 3, 0, 9, 5, 2};
    InsertionSort(A, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]); /* print every element of the array */
    }
}