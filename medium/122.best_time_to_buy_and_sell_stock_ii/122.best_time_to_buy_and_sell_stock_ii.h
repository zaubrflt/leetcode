#include <vector>
#include <algorithm>

class Solution1 {
public:
  int maxProfit(std::vector<int>& prices) {
    int benefit = 0;
    int slow = 0;
    int fast = 1;
    while (fast <= prices.size() - 1) {
      int tmp = prices[fast] - prices[slow];
      if (tmp > 0) {
        benefit += tmp;
      }
      slow = fast;
      fast++;
    }
    return benefit;
  }
};

class Solution2 {
public:
  int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = std::max(dp[i - 1][0], (dp[i - 1][1] + prices[i]));
      dp[i][1] = std::max(dp[i - 1][1], (dp[i - 1][0] - prices[i]));
    }
    return dp[n - 1][0];
  }
};
