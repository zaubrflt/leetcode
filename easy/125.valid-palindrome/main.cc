#include "../../lib/leetcode.h"
#include "125.valid-palindrome.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "test 1 -----------------------" << std::endl;
    Solution so;
    std::string s = "A man, a plan, a canal: Panama";
    if (so.isPalindrome(s) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 -----------------------" << std::endl;
    Solution so;
    std::string s = "race a car";
    if (so.isPalindrome(s) == false) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 -----------------------" << std::endl;
    Solution so;
    std::string s = " ";
    if (so.isPalindrome(s) == true) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
