/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:

Input: n = 27
Output: true
Example 2:

Input: n = 0
Output: false
Example 3:

Input: n = 9
Output: true
Example 4:

Input: n = 45
Output: false

Constraints:

-2^31 <= n <= 2^31 - 1

Follow up: Could you do it without using any loop / recursion?
3 9 27 81 243 729 2187
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && MAX_POWER_OF_TREE % n == 0;
    }
private:
    const int MAX_POWER_OF_TREE = 1162261467;
};