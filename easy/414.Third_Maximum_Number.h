/*
Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation: The third maximum is 1.

Example 2:

Input: nums = [1,2]
Output: 2
Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

Follow up: Can you find an O(n) solution?

*/

#include <vector>

using std::vector;

class Solution1 {
public:
    int thirdMax(vector<int>& nums) {
        int Max = INT_MIN, second = INT_MIN, third = INT_MIN;
        bool hasThird = false;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (tmp > Max) Max = tmp;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (tmp != Max && tmp > second) second = tmp;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if (tmp != Max && tmp != second && tmp >= third) {
                hasThird = true;
                third = tmp;
            }
        }
        return hasThird ? third : Max;
    }
};

class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        long Max = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for (const auto& num : nums) {
            if (num == Max || num == second || num == third) {
                continue;
            }

            if (num > Max) {
                third = second;
                second = Max;
                Max = num;
            } else if (num > second) {
                third = second;
                second = Max;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        return third == LONG_MIN ? Max : third;
    }
};