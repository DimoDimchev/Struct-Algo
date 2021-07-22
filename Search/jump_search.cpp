#include<iostream>
#include<cmath>
using namespace std;

int JumpSearch(int A[], int targetElement, int arraySize){
    int step = sqrt(arraySize);
    int prev = 0;

    while(A[step] <= targetElement && step < arraySize) { 
      // the control will continue to jump the blocks 
      prev = step;  // shift the block
      step += sqrt(arraySize);
      if(step > arraySize - 1)  // if step exceeds the array size
         return -1; 
   }

   for(int x = prev; x < step; x++) { //linear search in current block
      if(A[x] == targetElement)
         return x; //position of element being searched 
   }
   return -1;
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    int A[] = {2, 3, 4, 5, 7, 9, 12};
    int target = 9;
    int n = sizeof(A) / sizeof(A[0]);
    int result = JumpSearch(A, target, n);

    // Print the index where 'x' is located
    cout << "\nNumber " << target << " is at index " << result;
    return 0;
}