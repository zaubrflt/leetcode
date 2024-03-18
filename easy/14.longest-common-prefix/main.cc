#include "../../lib/leetcode.h"
#include "14.longest-common-prefix.h"

int main (int argc, char *argv[])
{
  {
    std::cout << "test 1 -----------------------" << std::endl;
    Solution so;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string ret = so.longestCommonPrefix(strs);
    if (ret == "fl") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
      std::cout << "ret: " << ret << std::endl;
    }
  }

  {
    std::cout << "test 2 -----------------------" << std::endl;
    Solution so;
    std::vector<std::string> strs = {"dog", "racecar", "car"};
    std::string ret = so.longestCommonPrefix(strs);
    if (ret == "") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
      std::cout << "ret: " << ret << std::endl;
    }
  }

  {
    std::cout << "test 3 -----------------------" << std::endl;
    Solution so;
    std::vector<std::string> strs = {"a"};
    std::string ret = so.longestCommonPrefix(strs);
    if (ret == "a") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
      std::cout << "ret: " << ret << std::endl;
    }
  }

  {
    std::cout << "test 4 -----------------------" << std::endl;
    Solution so;
    std::vector<std::string> strs = {"flower", "flower", "flower", "flower"};
    std::string ret = so.longestCommonPrefix(strs);
    if (ret == "flower") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
      std::cout << "ret: " << ret << std::endl;
    }
  }

  {
    std::cout << "test 5 -----------------------" << std::endl;
    Solution so;
    std::vector<std::string> strs = {"", "cbc", "c", "ca"};
    std::string ret = so.longestCommonPrefix(strs);
    if (ret == "") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
      std::cout << "ret: " << ret << std::endl;
    }
  }
  return 0;
}
