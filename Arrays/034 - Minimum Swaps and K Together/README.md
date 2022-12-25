# Minimum swaps and K together

### Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.
 

#### Example 1:

    Input : 
    arr[ ] = {2, 1, 5, 6, 3} 
    K = 3
    Output : 
    1
    Explanation:
    To bring elements 2, 1, 3 together,
    swap index 2 with 4 (0-based indexing),
    i.e. element arr[2] = 5 with arr[4] = 3
    such that final array will be- 
    arr[] = {2, 1, 3, 6, 5}

#### Example 2:

    Input : 
    arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
    K = 6 
    Output :  
    2 
    Explanation: 
    To bring elements 2, 5, 4 together, 
    swap index 0 with 2 (0-based indexing)
    and index 4 with 6 (0-based indexing)
    such that final array will be- 
    arr[] = {9, 7, 2, 5, 4, 7, 8}

#### Example 3:

    Input : 
    arr[ ] = {2, 1, 7, 9, 5, 6, 4, 8, 7, 4, 9, 10, 7, 8, 4, 3, 2, 1}
    K = 6
    K = 6 
    Output :  
    4

#### Constraints

- 1 ≤ N ≤ 10^5
- 1 ≤ Arr[i], K ≤ 10^7



