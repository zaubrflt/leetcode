#include <string>
#include <vector>

class Solution {
public:
  std::string reverseWords(std::string s)
  {
    std::vector<std::string> rets;
    std::string str;
    int start;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        if (str.empty() == false) {
          rets.push_back(str);
          str.clear();
        }
      } else {
        if (str.empty()) {
          start = i;
        }
        str += s[i];
      }
    }
    if (str.empty() == false) {
      rets.push_back(str);
    }
    std::string ret = rets[rets.size() - 1];
    for (int i = rets.size() - 2; i >= 0; i--) {
      ret += " " + rets[i];
    }
    return ret;
  }
};