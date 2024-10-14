#include <vector>
#include <unordered_set>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums)
  {
    std::unordered_set<int> numSet;
    for (int i = 0; i < nums.size(); i++) {
      numSet.insert(nums[i]);
    }
    int ret = 0;
    for (auto & num : numSet) {
      if (!numSet.count(num - 1)) {
        // 有了这个判断条件，可以保证是从连续序列的第一个数开始计数，
        // 避免了无效的遍历
        int curr = num;
        int cnt = 0;
        while (numSet.count(curr)) {
          cnt++;
          curr++;
        }
        if (cnt > ret) ret = cnt;
      }
    }
    return ret;
  }
};