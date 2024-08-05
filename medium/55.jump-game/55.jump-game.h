#ifndef MEDIUM_55_JUMP_GAME_H
#define MEDIUM_55_JUMP_GAME_H

#include <vector>
#include <iostream>

class Solution {
public:
  bool canJump(std::vector<int>& nums)
  {
    int maxDistance = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > maxDistance) {
        return false;
      }
      if (maxDistance < i + nums[i]) {
        maxDistance = i + nums[i];
      }
    }
    return nums.size() - 1 <= maxDistance;
  }
};

#endif  // MEDIUM_55_JUMP_GAME_H