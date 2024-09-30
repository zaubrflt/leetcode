#include <string>
#include <deque>

class Solution {
public:
  std::string simplifyPath(std::string path)
  {
    std::deque<std::string> pathDeque;
    std::size_t start = 0;
    std::size_t pos = 0;
    do
    {
      pos = path.find_first_of('/', start);
      if (start != pos) {
        std::string subPath = "";
        if (pos != std::string::npos) {
          subPath = path.substr(start, pos - start);
        } else {
          subPath = path.substr(start);
        }
        if (subPath == ".." && pathDeque.empty() == false) {
          pathDeque.pop_back();
        } else if (subPath != "." && subPath != ".." && subPath != "") {
          pathDeque.push_back(subPath);
        }
      }
      start = pos + 1;
    } while (pos < path.size());

    std::string ret = "/";
    while (pathDeque.empty() == false) {
      auto str = pathDeque.front();
      pathDeque.pop_front();
      ret += str + "/";
    }
    if (ret != "/") ret.pop_back();
    return ret;
  }
};
