#include <vector>
#include <numeric>
#include <algorithm>

#include <iostream>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums)
  {
    int len = INT_MAX;
    int start = 0, end = 0;
    int sum = 0;
    while (start < nums.size() && end < nums.size()) {
      sum += nums[end];
      while (sum >= target) {
        len = std::min(len, end - start + 1);
        sum -= nums[start];
        start++;
      }
      end++;
    }
    return len == INT_MAX ? 0 : len;
  }
};