/*
Given an integer array nums, find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide
and conquer approach, which is more subtle.
*/

#include <vector>

using std::vector;

// Dynamic Programming
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums) {
            pre = std::max(pre + x, x);
            maxAns = std::max(maxAns, pre);
        }
        return maxAns;
    }
};

// Divide and Conquer
class Solution2 {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status& l, Status& r) {
        int iSum = l.iSum + r.iSum;
        int lSum = std::max(l.lSum, l.iSum + r.lSum);
        int rSum = std::max(r.rSum, r.iSum + l.rSum);
        int mSum = std::max(std::max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int>& a, int l, int r) {
        if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};