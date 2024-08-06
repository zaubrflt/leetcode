#include <vector>
#include <iostream>

class Solution {
public:
  int jump(std::vector<int>& nums)
  {
    std::cout << std::endl;
    int last = nums.size() - 1;
    int cnt = 0;

    for (int i = 0; i < nums.size() && last != 0;) {
      bool match = false;
      for (int j = 1; j <= nums[i]; j++) {
        if (i + j == last) {
          match = true;
          last = i;
          cnt++;
          i = 0;
          break;
        }
      }
      if (!match) i++;
    }
    return cnt;
  }
};