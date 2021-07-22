## Binary search

- Find the middle element of the array and if it matches with the target element return the index. Else compare the elements and recursively call the same function on the right subarray if the target is larger than the middle element and vice versa. If the target isn't found return -1
- Requires a sorted array
- Time complexity O(logn)

## Jump search

- Perform several jumps of size `m` in a sorted array of size `n`. When the element `Array[m]` becomes larger than the target element perform a linear search from `Array[m - 1]` to `Array[m]`
- Requires a sorted array
- The optimal step size is √n
- Time complexity O(√n)

## Interpolation search

- Use a predefined formula `(pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ])`. The idea of this formula is to return a higher value when element to be searched is closer to `arr[hi]` and vice versa. After finding `pos` compare `arr[pos]` to the target element. If they match return `pos`. If `arr[pos]` is smaller than the target element then the target element is in the right subarray and we call the method recursively only for the right subarray. If `arr[pos]` is larger than the target we do the opposite. If the element isn't found return -1
- Requires a sorted array
- Performs best when elements in array are uniformly distributed
- Recursive algorithm
- Time complexity: O(log log n) in average case
