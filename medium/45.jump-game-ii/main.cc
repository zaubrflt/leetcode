#include "45.jump-game-ii.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    if (so.jump(nums) == 2) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> nums = {2, 3, 0, 1, 4};
    if (so.jump(nums) == 2) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}