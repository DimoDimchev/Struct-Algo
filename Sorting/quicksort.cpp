#include<iostream>
using namespace std;

int Partition(int A[], int start, int end){
    int i;
    int pivot = A[end]; // pivot is always at the end
    int pIndex = start;
    for(i = start; i < end; i++){
        if(A[i] <= pivot){
            swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    swap(A[pIndex], A[end]);
    return pIndex;
}

void QuickSort(int A[], int start, int end){
    if(start >= end) return; // base case

    // partition the array
    int pIndex = Partition(A, start, end);
    QuickSort(A, start, pIndex - 1); // sort segment left of the pivot
    QuickSort(A, pIndex + 1, end); // sort segment right of the pivot
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int i;
    int A[] = {2, 6, 1, 9, 12, 3, 15, 20};
    QuickSort(A, 0, 7);
    for(i = 0;i < 8;i++) cout<<A[i]<<" ";
}