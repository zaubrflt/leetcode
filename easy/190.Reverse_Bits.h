/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages such as Java, there is no unsigned integer type.
In this case, both input and output will be given as a signed integer type.
They should not affect your implementation,
as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation.
Therefore, in Example 2 above, the input represents the signed integer -3
and the output represents the signed integer -1073741825.
Follow up:

If this function is called many times, how would you optimize it?

 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596,
so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293,
so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Constraints:

The input must be a binary string of length 32

*/

#include <cstdint>

class Solution1 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int i = 32;
        while (i--) {
            ret <<= 1;
            ret += n & 1;
            n >>= 1;
        }
        return ret;
    }
};

/*
 * 首先将原来的 32 位分为 2 个 16 位的块。
 * 然后将 16 位块分成 2 个 8 位的块。
 * 然后继续将这些块分成更小的块，直到达到 1 位的块。
 * 在上述每个步骤中，将中间结果合并为一个整数，作为下一步的输入。
 */
class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);      // 交换前 16 位与后 16 位
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};