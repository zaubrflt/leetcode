#include "../../lib/leetcode.h"
#include "122.best-time-to-buy-and-sell-stock-ii.h"

int main (int argc, char *argv[]) {
  {
    std::cout << "Solution1 test 1 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    if (so.maxProfit(prices) == 7) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "Solution1 test 2 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {1, 2, 3, 4, 5};
    if (so.maxProfit(prices) == 4) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "Solution1 test 3 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {7, 6, 4, 3, 1};
    if (so.maxProfit(prices) == 0) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
{
    std::cout << "Solution2 test 1 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    if (so.maxProfit(prices) == 7) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "Solution2 test 2 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {1, 2, 3, 4, 5};
    if (so.maxProfit(prices) == 4) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "Solution2 test 3 ----------------------- ";
    Solution1 so;
    std::vector<int> prices = {7, 6, 4, 3, 1};
    if (so.maxProfit(prices) == 0) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  return 0;
}
