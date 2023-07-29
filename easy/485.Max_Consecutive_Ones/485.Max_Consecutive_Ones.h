#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int cnt = 0, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                max = std::max(cnt, max);
                cnt = 0;
            }
        }
        return std::max(cnt, max);
    }
};
