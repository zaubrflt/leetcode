#include "../../lib/leetcode.h"
#include "169.majority-element.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "test 1 -----------------------" << std::endl;
    Solution so;
    std::vector<int> nums = {3, 2, 3};
    if (so.majorityElement(nums) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 -----------------------" << std::endl;
    Solution so;
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    if (so.majorityElement(nums) == 2) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 -----------------------" << std::endl;
    Solution so;
    std::vector<int> nums = {6, 5, 5};
    if (so.majorityElement(nums) == 5) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 4 -----------------------" << std::endl;
    Solution so;
    std::vector<int> nums = {10, 9, 9, 9, 10};
    if (so.majorityElement(nums) == 9) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
