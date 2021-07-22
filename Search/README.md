## Binary search
- Find the middle element of the array and if it matches with the target element return the index. Else compare the elements and recursively call the same function on the right subarray if the target is larger than the middle element and vice versa. If the target isn't found return -1
- Requires a sorted array
- Time complexity O(logn)

## Jump search
- Perform several jumps of size m in a sorted array of size n. When the element Array[m] becomes larger than the target element perform a linear search from Array[m - 1] to Array[m]
- Requires a sorted array
- The optimal step size is √n
- Time complexity O(√n)
