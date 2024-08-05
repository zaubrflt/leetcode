#include "55.jump-game.h"

#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> nums = {2, 3, 1, 1, 4};
    if (so.canJump(nums) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> nums = {3, 2, 1, 0, 4};
    if (so.canJump(nums) == false) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::vector<int> nums = {0};
    if (so.canJump(nums) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 4 ----------------------- ";
    Solution so;
    std::vector<int> nums = {0, 2, 3};
    if (so.canJump(nums) == false) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 5 ----------------------- ";
    Solution so;
    std::vector<int> nums = {2, 0, 0};
    if (so.canJump(nums) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 6 ----------------------- ";
    Solution so;
    std::vector<int> nums = {1, 0, 1, 0};
    if (so.canJump(nums) == false) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 7 ----------------------- ";
    Solution so;
    std::vector<int> nums = {2, 5, 0, 0};
    if (so.canJump(nums) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  return 0;
}
