# Rearrange Array Elements by Sign

### You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

### You should rearrange the elements of nums such that the modified array follows the given conditions:

### Every consecutive pair of integers have opposite signs.
### For all integers with the same sign, the order in which they were present in nums is preserved.
### The rearranged array begins with a positive integer.
#### Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


#### Example 1:

    Input:  arr[] = {1, 2, 3, -4, -1, 4}
    Output: arr[] = {-4, 1, -1, 2, 3, 4}

#### Example 2:

    Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
    Output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}

#### Constraints

- 2 <= nums.length <= 2 * 10^5
- 1 <= |nums[i]| <= 10^5

