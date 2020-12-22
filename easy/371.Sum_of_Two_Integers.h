/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1

*/

/*
 * a ^ b可以得到两数相加不进位的加法结果
 * (a & b) << 1可以得到两数相加产生的进位
*/
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            auto carry = ((unsigned int)(a & b)) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};