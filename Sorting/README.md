## General knowledge about sorting algorithms
- Sorting is arranging the elements of a list or collection in increasing or decreasing order based on a property
- Sorting algorithms are classified based on the following properties:
	- Time complexity
	- Space complexity
	- Stability 
	- Internal sort vs external sort
	- Recursive vs non-recursive 
- An in-place sorting algorithm takes constant amount of extra memory


## Selection sort
- Find the minimum element of an array and swap its position with index n. Increase n + 1 and repeat until the array is sorted 
- Very easy to implement and understand
- Slow algorithm
- Time complexity = O(n2)

## Bubble sort
- Traverse the array and compare element at index n with element at element at index n + 1. If the second element is smaller than the former they are swapped. Repeat this until array is sorted
- Slow algorithm, as good as selection sort
- Time complexity = O(n2)

## Insertion sort
- Sort one item at a time. The array is divided in two subsets: sorted and unsorted subset. When the unsorted subset is empty the algorithm is finished
- Considered better than selection and bubble sort
- Time complexity = O(n2)

## Merge sort
- Split the array into two halves which get sorted recursively. After that merge both arrays into the original array
- A divide and conquer algorithm
- A recursive, stable algorithm
- Time complexity = O(nlogn) at worst case

## Quicksort
- Select a pivot and rearrange the list so that all elements smaller than the pivot are to the left and vice versa. After that sort the arrays to the left and right of the pivot
- A divide and conquer, recursive algorithm
- Time complexity = O(nlogn) at average case
