# Array Subset of another array

### Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 
 

#### Example 1:

    Input:
    a1[] = {11, 1, 13, 21, 3, 7}
    a2[] = {11, 3, 7, 1}
    Output:
    Yes
    Explanation:
    a2[] is a subset of a1[]

#### Example 2:

    Input:
    a1[] = {1, 2, 3, 4, 5, 6}
    a2[] = {1, 2, 4}
    Output:
    Yes
    Explanation:
    a2[] is a subset of a1[]

#### Example 3:

    Input:
    a1[] = {10, 5, 2, 23, 19}
    a2[] = {19, 5, 3}
    Output:
    No
    Explanation:
    a2[] is not a subset of a1[]

#### Constraints

- 1 <= n,m <= 10^5
- 1 <= a1[i], a2[j] <= 10^5

