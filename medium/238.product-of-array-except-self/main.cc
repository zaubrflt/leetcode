#include "238.product-of-array-except-self.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> ret = {24, 12, 8, 6};
    if (so.productExceptSelf(nums) == ret) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> ret = {0, 0, 9, 0, 0};
    if (so.productExceptSelf(nums) == ret) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  return 0;
}
