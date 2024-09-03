#include "167.two-sum-ii-input-array-is-sorted.h"
#include "../../lib/leetcode.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> ret = {1, 2};
    if (so.twoSum(numbers, target) == ret) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> numbers = {2, 3, 4};
    int target = 6;
    std::vector<int> ret = {1, 3};
    if (so.twoSum(numbers, target) == ret) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::vector<int> numbers = {-1, 0};
    int target = -1;
    std::vector<int> ret = {1, 2};
    if (so.twoSum(numbers, target) == ret) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  return 0;
}
