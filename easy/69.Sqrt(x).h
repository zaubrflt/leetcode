/*
Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated,
and only the integer part of the result is returned.

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 
Constraints:
0 <= x <= 2^31 - 1
*/

#include <cmath>

class Solution1 {
public:
    int mySqrt(int x) {
        int n = 0;
        while (pow(n, 2) <= x) n++;
        return n - 1;
    }
};

class Solution2 {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x / 2 + 1;

        while(left <= right){
            long long mid = (left + right) / 2;
            long long product = mid * mid;
            if (product == x) {
                return mid;
            } else if (product < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};