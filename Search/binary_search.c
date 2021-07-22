#include<stdlib.h>
#include<stdio.h>

int binarySearch(int A[], int target, int leftPointer, int rightPointer){
    if(rightPointer >= leftPointer){
        int mid = leftPointer + (rightPointer - leftPointer) / 2; // find the middle element of the array

        if(A[mid] == target) return mid; // return the middle element if it's the target
        if(A[mid] > target) return binarySearch(A, target, leftPointer, mid - 1); // do a binary search on the left part of the array if the middle element is larger than the target
        if(A[mid] < target) return binarySearch(A, target, mid + 1, rightPointer); // do a binary search on the right part of the array if the middle element is smaller than the target
    }
    return -1; // return this if target isn't in the array
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {2, 3, 4, 5, 7, 9, 12};
    int target = 9;
    int leftPointer = 0;
    int rightPointer = sizeof(A) / sizeof(A[0]); // calculate the lenght of the array
    int result = binarySearch(A, target, leftPointer, rightPointer - 1);

    if(result == -1) printf("Target not found");
    else printf("Target found at index %d\n", result);
}