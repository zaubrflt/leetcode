/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true

Constraints:

-2^31 <= n <= 2^31 - 1

Follow up: Could you solve it without loops/recursion?

*/

/*
算法1:

我们首先检查 n 是否为 2 的幂: x > 0 and x & (x - 1) == 0.

现在的问题是区分 2 的偶数幂(当 xx 是 4 的幂时)和 2 的奇数幂(当 xx 不是 4 的幂时)
在二进制表示中, 这两种情况都只有一位为 1，其余为 0.

有什么区别？在第一种情况下(4 的幂), 1 处于偶数位置: 第 0 位, 第 2 位, 第 4 位等; 在第二种情况下, 1 处于奇数位置.

因此 4 的幂与数字 (101010...10) 相与或得到 0, 即 4^a ^ (101010...10) == 0

(101010...10) 用十六进制表示为 : (aaaaaaaa)

作者：LeetCode
链接：https://leetcode-cn.com/problems/power-of-four/solution/4de-mi-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Solution1 {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0xaaaaaaaa) == 0);
    }
};

/*
算法:

我们首先检查 x 是否为 2 的幂: x > 0 and x & (x - 1) == 0. 然后可以确定 x = 2^a, 若 x 为 4 的幂则 a 为偶数.

下一步是考虑 a = 2k 和 a = 2k + 1 两种情况, 将 x 对 3 进行取模:
(2^2k mod 3) = (4^k mod 3) = ((3 + 1)^k mod 3) = 1
(2^(2k + 1) mod 3) = ((2 * 4^k) mod 3) = ((2 * (3 + 1)^k) mod 3) = 2

若 x 为 2 的幂且 x % 3 == 1, 则 x 为 4 的幂,

作者：LeetCode
链接：https://leetcode-cn.com/problems/power-of-four/solution/4de-mi-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

class Solution2 {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && (n % 3 == 1);
    }
};