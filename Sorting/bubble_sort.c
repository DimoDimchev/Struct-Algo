#include<stdlib.h>
#include<stdio.h>

void BubbleSort(int A[], int n){ // pass an array and the number of elements
    int i, j, flag;
    for(i = 0; i < n-2; i++){ // traverse the array
        for(j = 0; j < n - i - 1 ; j++){ // compare adjacent elements
            if(A[j] > A[j + 1]){ // swap the elements if element j + 1 is smaller than element j
                int temp = A[j]; 
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){ // if the array is already sorted break the loop
            break;
        }
    }
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {3, 5, 2, 1, 7, 6, 9};
    BubbleSort(A, 7);
    for (int i = 0; i < 7; i++) {
        printf("%d ", A[i]); /* print every element of the array */
    }
}