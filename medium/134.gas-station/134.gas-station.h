#include <vector>
#include <algorithm>

class Solution {
public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
  {
    int i = 0;
    int n = gas.size();
    while (i < n) {
      int left = 0;
      int cnt = 0;
      while (cnt < n) {
        int j = (i + cnt) % n;
        left = left + gas[j] - cost[j];
        if (left < 0) {
          break;
        } else {
          cnt++;
        }
      }
      if (cnt == n) {
        return i;
      } else {
        i += cnt + 1;
      }
    }
    return -1;
  }
};