/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers
within the 32-bit signed integer range: [-2^31, 2^31 - 1].
For the purpose of this problem, assume that your function returns 0
when the reversed integer overflows.
*/

#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int pop, rev = 0;
        while (x != 0) {
            pop = x % 10;
            x /= 10;
            // 当 temp = rev * 10 + pop 时会导致溢出
            // 考虑 rev 是正数的情况:
            // 1. 如果 temp = rev * 10 + pop 导致了溢出, 那么一定是 rev >= INT_MAX / 10
            // 2. 如果 rev > INT_MAX / 10, 那么 temp = rev * 10 + pop 一定会导致溢出
            // 3. 如果 rev == INT_MAX / 10, 那么只要当 pop > 7,  temp = rev * 10 + pop就会溢出
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};