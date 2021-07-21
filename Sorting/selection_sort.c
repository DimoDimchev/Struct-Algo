#include<stdlib.h>
#include<stdio.h>

void SelectionSort(int A[], int n){ // pass an array and the number of elements
    int i, j;
    for(i = 0; i < n-1; i++){ // n - 2 traversals are needed
        int minEl = i;
        for(j = i + 1; j < n; j++){
            if(A[j] < A[minEl]) minEl = j; // update the index of the smallest element
        }
        int temp = A[i]; // swap the positions of the two elements
        A[i] = A[minEl];
        A[minEl] = temp;
    }
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {1, 4, 3, 0, 9, 5, 2};
    SelectionSort(A, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]); /* print every element of the array */
    }
}