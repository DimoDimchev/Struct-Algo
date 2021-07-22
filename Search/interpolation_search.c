#include<stdlib.h>
#include<stdio.h>

int interpolationSearch(int arr[], int leftPointer, int rightPointer, int target)
{
    int pos;
    // Since array is sorted, an element present in array must be in range defined by corner
    if (leftPointer <= rightPointer && target >= arr[leftPointer] && target <= arr[rightPointer]) {
        // Probing the position with keeping uniform distribution in mind.
        pos = leftPointer + (((double)(rightPointer - leftPointer) / (arr[rightPointer] - arr[leftPointer])) * (target - arr[leftPointer]));
 
        // Condition of target found
        if (arr[pos] == target)
            return pos;
 
        // If x is larger, x is in right sub array
        if (arr[pos] < target)
            return interpolationSearch(arr, pos + 1, rightPointer, target);
 
        // If x is smaller, x is in left sub array
        if (arr[pos] > target)
            return interpolationSearch(arr, leftPointer, pos - 1, target);
    }
    return -1;
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {2, 3, 4, 5, 6, 7, 8};
    int target = 4;
    int result = interpolationSearch(A, 0, 6, target);

    if(result == -1) printf("Target not found");
    else printf("Target found at index %d\n", result);
}