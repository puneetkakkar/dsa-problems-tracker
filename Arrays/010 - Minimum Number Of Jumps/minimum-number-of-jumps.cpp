
/**
 * @file minimum-number-of-jumps.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-07-13
 *
 * @note Iterative Algorithm - 
 * 1. If n <= 1, then return 0, because that is the destination
 * 2. If arr[0] == 0 then return -1 as answer (no jumps are possible)
 * 3. Now, Initialize maxrange and steps with arr[0], and jumps with 1 (as 1
 *    jump will be required)
 * 4. Now, starting iteration from index 1, the above values are updated as
 *    follows:
 *      a. First we test whether we have reached the end of the array, in that
 *         case we just need to return the jump variable
 *          if (i == arr.length - 1) return jump;
 *      b. Next we update the maxrange. This is equal to the maximum of maxrange
 *         and i+arr[i](the number of steps we can take from the current
 *         position).
 *          maxrange = max(maxrange,i+arr[i]);
 *      c. We used up a step to get to the current index, so steps has to be 
 *         decreased. 
 *         step--; 
 *      d. If no more steps are remaining (i.e. steps=0, then we must 
 *         have used a jump. Therefore increase jump. Since we know that it is possible to 
 *         reach maxrange, we again initialize the steps to the number of steps to reach 
 *         maxReach from position i. But before re-initializing step, we also check whether 
 *         a step is becoming zero or negative. In this case, It is not possible to reach 
 *         further. 
 *          if (step == 0) { 
 *              jump++; 
 *              if(i>=maxReach) return -1; 
 *              step = maxReach - i;
 *          }
 * 5. Return the jump value
 *
 * 
 * TIME COMPLEXITY O(N)
 * SPACE COMPLEXITY O(1)
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minJumps(int arr[], int n) {
    if (n <= 1) {
      return 0;
    }

    if (arr[0] == 0) {
      return -1;
    }

    int jumps = 1;
    int currMaxReach = arr[0];
    int steps = arr[0];

    for (int i = 1; i < n - 1; ++i) {
      currMaxReach = max(currMaxReach, i + arr[i]);
      --steps;

      if (steps == 0) {
        jumps += 1;
        if (i >= currMaxReach) {
          return -1;
        }
        steps = currMaxReach - i;
      }
    }

    return jumps;
  }
};

// { Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution obj;
    cout << obj.minJumps(arr, n) << endl;
  }
  return 0;
}
// } Driver Code Ends