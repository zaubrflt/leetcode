#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> L(nums.size()), R(nums.size());
    L[0] = 1;
    R[nums.size() - 1] = 1;
    for (int i = 1; i < nums.size(); i++) {
      L[i] = L[i - 1] * nums[i - 1];
    }
    for (int i = nums.size() - 2; i > -1; i--) {
      R[i] = R[i + 1] * nums[i + 1];
    }
    std::vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
      ret.push_back(L[i] * R[i]);
    }
    return ret;
  }
};