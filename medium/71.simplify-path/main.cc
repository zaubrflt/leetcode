#include "71.simplify-path.h"

#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::string path = "/home/";
    if (so.simplifyPath(path) == "/home") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::string path = "/home//foo/";
    if (so.simplifyPath(path) == "/home/foo") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::string path = "/home/user/Documents/../Pictures";
    if (so.simplifyPath(path) == "/home/user/Pictures") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 4 ----------------------- ";
    Solution so;
    std::string path = "/../";
    if (so.simplifyPath(path) == "/") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 5 ----------------------- ";
    Solution so;
    std::string path = "/.../a/../b/c/../d/./";
    if (so.simplifyPath(path) == "/.../b/d") {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
