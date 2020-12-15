/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9].
8 is the missing number in the range since it does not appear in nums.

Example 4:

Input: nums = [0]
Output: 1
Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1].
1 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 10^4
0 <= nums[i] <= n
All the numbers of nums are unique.

*/

#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> records = vector<int>(MAX_SIZE, 0);
        for (int i = 0; i < nums.size(); ++i) {
            records[i]++;
        }
        for (int i = 0; i < nums.size() + 1; ++i) {
            if (records[i] == 0) return i;
        }
        return -1;
    }
private:
    const int MAX_SIZE = 10000;
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        set<int> numSet;
        for (int num : nums) numSet.insert(num);

        for (int i = 0; i < numSet.size() + 1; ++i) {
            if (numSet.find(i) == numSet.end()) {
                return i;
            }
        }
        return -1;
    }
};

/*
位运算

分析:

由于异或运算（XOR）满足结合律, 并且对一个数进行两次完全相同的异或运算会得到原来的数, 因此我们可以通过异或运算找到缺失的数字.

算法:

我们知道数组中有 nn 个数，并且缺失的数在 [0..n][0..n] 中.
因此我们可以先得到 [0..n][0..n] 的异或值，再将结果对数组中的每一个数进行一次异或运算.
未缺失的数在 [0..n][0..n] 和数组中各出现一次, 因此异或后得到 0.
而缺失的数字只在 [0..n][0..n] 中出现了一次, 在数组中没有出现, 因此最终的异或结果即为这个缺失的数字.

在编写代码时，由于 [0..n][0..n] 恰好是这个数组的下标加上 nn，因此可以用一次循环完成所有的异或运算，例如下面这个例子:

下标	0	1	2	3
数字	0	1	3	4

可以将结果的初始值设为 n, 再对数组中的每一个数以及它的下标进行一个异或运算, 即:

missing = 4 ∧ (0 ∧ 0) ∧ (1 ∧ 1) ∧ (2 ∧ 3) ∧ (3 ∧ 4)
        = (4 ∧ 4) ∧ (0 ∧ 0) ∧ (1 ∧ 1) ∧ (3 ∧ 3) ∧ 2
        = 0 ∧ 0 ∧ 0 ∧ 0 ∧ 2
        = 2
​	
作者：LeetCode
链接：https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-leetcode/
来源：力扣（LeetCode）

*/

class Solution3 {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};