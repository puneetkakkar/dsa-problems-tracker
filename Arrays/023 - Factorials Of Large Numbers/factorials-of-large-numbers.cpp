
/**
 * @file factorials-of-large-numbers.cpp
 * @author Puneet Kakkar (puneetkakkar91@gmail.com)
 * @brief Given an integer N, find its factorial.
 * @version 0.1
 * @date 2022-09-03
 * @note Algorithm
 * 1. Create a vector vec[].
 * 2. Initialize value stored in vector as 1.
 * 3. Multiply x with vec[] and update vec[] to store the multiplication result for all the numbers from x = 1 to n.
 * 4. To multiply a number x with the number stored in vec[], one by one multiply x with every digit of vec[].
 * 5. To implement multiply function perform the following steps:
 *  5.1. Initialize carry as 0. 
 *  5.2. Do following for i = 0 to vec_size - 1 
 *      5.2.1 Find value of vec[i] * x + carry. Let this value be product. 
 *      5.2.2 Update vec[i] by storing the last digit of product in it. 
 *      5.2.3 Update carry by storing the remaining digits in carry. 
 *  5.3 Put all digits of carry in vec[] and increase vec_size by the number of digits in carry.
 * 
 * TIME COMPLEXITY - O(N^2)
 * SPACE COMPLEXITY - O(1)
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> vec;
        vec.push_back(1);
        
        for(int i=1; i <= N; ++i) {
            int carry = 0;
            for(int j = 0; j < vec.size(); ++j) {
                int num = (vec[j] * i) + carry;
                if(num <= 9) {
                    vec[j] = num;
                    carry = 0;
                } else {
                    carry = num/10;
                    vec[j] = num%10;
                }
            }
            while(carry > 0) {
                vec.push_back(carry%10);
                carry /= 10;
            }
        }
        
        reverse(vec.begin(), vec.end());
        
        return vec;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}