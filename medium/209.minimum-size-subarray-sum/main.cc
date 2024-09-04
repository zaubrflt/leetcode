#include "209.minimum-size-subarray-sum.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    int target = 7;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    if (so.minSubArrayLen(target, nums) == 2) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    int target = 4;
    std::vector<int> nums = {1, 4, 4};
    if (so.minSubArrayLen(target, nums) == 1) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    int target = 11;
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    if (so.minSubArrayLen(target, nums) == 0) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
