#include "274.h-index.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> nums = {3, 0, 6, 1, 5};
    if (so.hIndex(nums) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> nums = {1, 3, 1};
    if (so.hIndex(nums) == 1) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::vector<int> nums = {6, 1, 3, 0, 5};
    if (so.hIndex(nums) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 4 ----------------------- ";
    Solution so;
    std::vector<int> nums = {0, 1, 3, 6, 5};
    if (so.hIndex(nums) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 5 ----------------------- ";
    Solution so;
    std::vector<int> nums = {100};
    if (so.hIndex(nums) == 1) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 6 ----------------------- ";
    Solution so;
    std::vector<int> nums = {11, 15};
    if (so.hIndex(nums) == 2) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}