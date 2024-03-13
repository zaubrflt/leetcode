#include <string>

class Solution {
public:
  int romanToInt(std::string s) {
    int ret = convert(s[0]);
    char last = s[0];
    for (int i = 1; i < s.size(); i++) {
      if (convert(last) < convert(s[i])) {
        ret -= 2 * convert(last);
      }
      ret += convert(s[i]);
      last = s[i];
    }
    return ret;
  }

private:
  int convert(char c)
  {
    if (c == 'I') {
      return 1;
    } else if (c == 'V') {
      return 5;
    } else if (c == 'X') {
      return 10;
    } else if (c == 'L') {
      return 50;
    } else if (c == 'C') {
      return 100;
    } else if (c == 'D') {
      return 500;
    } else if (c == 'M') {
      return 1000;
    }
    return 0;
  }
};
