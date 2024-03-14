#include "../../lib/leetcode.h"
#include "58.length-of-last-word.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::string str = "Hello World";
    if (so.lengthOfLastWord(str) == 5) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::string str = "   fly me   to   the moon  ";
    if (so.lengthOfLastWord(str) == 4) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::string str = "luffy is still joyboy";
    if (so.lengthOfLastWord(str) == 6) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  return 0;
}
