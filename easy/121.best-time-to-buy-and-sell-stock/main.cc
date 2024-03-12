#include "../../lib/leetcode.h"
#include "121.best-time-to-buy-and-sell-stock.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "test 1 -----------------------" << std::endl;
    Solution so;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    if (so.maxProfit(prices) == 5) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 -----------------------" << std::endl;
    Solution so;
    std::vector<int> prices = {7, 6, 4, 3, 1};
    if (so.maxProfit(prices) == 0) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
