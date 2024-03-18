#include <string>
#include <vector>

#include <iostream>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs)
  {
    if (strs.size() == 1) return strs[0];
    std::string str = "";
    std::string last_str = str;
    for (int i = 0; i < strs.size(); i++) {
      if (strs[i] == "") return "";
      for (int j = 0; j < strs[i].size(); j++) {
        str = strs[i].substr(0, j + 1);
        for (int k = i + 1; k < strs.size(); k++) {
          if (strs[k] == "") return "";
          if (str != strs[k].substr(0, j + 1)) {
            return last_str;
          }
          if (k == strs.size() - 1) {
            last_str = str;
          }
        }
      }
    }
    return last_str;
  }
};
