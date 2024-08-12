#include <vector>
#include <algorithm>

class Solution {
public:
  int hIndex(std::vector<int>& citations)
  {
    int maxH = citations[0] == 0 ? 0 : 1;
    auto nums = citations;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int current = std::min(nums[i], (int)(nums.size() - i));
      maxH = std::max(maxH, current);
    }
    return maxH;
  }
};