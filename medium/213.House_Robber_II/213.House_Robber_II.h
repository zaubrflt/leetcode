#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 1) return nums[0];

        return max(__rob(nums, 0, nums.size() - 2), __rob(nums, 1, nums.size() - 1));
    }
private:
    int __rob(vector<int>& nums, int start, int end) {
        int first = nums[start];
        int second = max(first, nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int tmp = second;
            second = max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }
};