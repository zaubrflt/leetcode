#include "../../lib/leetcode.h"
#include "13.roman-to-integer.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::string str = "III";
    if (so.romanToInt(str) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  
  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::string str = "IV";
    if (so.romanToInt(str) == 4) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::string str = "IX";
    if (so.romanToInt(str) == 9) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 4 ----------------------- ";
    Solution so;
    std::string str = "LVIII";
    if (so.romanToInt(str) == 58) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 5 ----------------------- ";
    Solution so;
    std::string str = "MCMXCIV";
    if (so.romanToInt(str) == 1994) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
