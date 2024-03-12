#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int benefit = 0;
    int slow = 0;
    int fast = 1;
    while (fast <= prices.size() - 1) {
      int tmp = prices[fast] - prices[slow];
      if (tmp > benefit) {
        benefit = tmp;
      }
      if (tmp < 0) {
        slow = fast;
      }
      fast++;
    }
    return benefit;
  }
};
