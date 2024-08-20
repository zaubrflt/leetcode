#include "151.reverse-words-in-a-string.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::string str = "the sky is blue";
    if (so.reverseWords(str) == "blue is sky the") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::string str = "  hello world  ";
    if (so.reverseWords(str) == "world hello") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::string str = "a good   example";
    if (so.reverseWords(str) == "example good a") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
