#include "134.gas-station.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  {
    std::cout << "test 1 ----------------------- ";
    Solution so;
    std::vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};
    if (so.canCompleteCircuit(gas, cost) == 3) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

  {
    std::cout << "test 2 ----------------------- ";
    Solution so;
    std::vector<int> gas = {2, 3, 4}, cost = {3, 4, 3};
    if (so.canCompleteCircuit(gas, cost) == -1) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }

    {
    std::cout << "test 3 ----------------------- ";
    Solution so;
    std::vector<int> gas = {5, 1, 2, 3, 4}, cost = {4, 4, 1, 5, 1};
    if (so.canCompleteCircuit(gas, cost) == 4) {
      std::cout << "pass" << std::endl;
    } else {
      std::cout << "no pass" << std::endl;
    }
  }
  return 0;
}
