#include "213.House_Robber_II.h"

#include <iostream>

int main(void)
{
    Solution solution;

    vector<int> v1 = {2, 3, 2};
    std::cout << (solution.rob(v1) == 3) << std::endl;
    vector<int> v2 = {1, 2, 3, 1};
    std::cout << (solution.rob(v2) == 4) << std::endl;
    vector<int> v3 = {0};
    std::cout << (solution.rob(v3) == 0) << std::endl;
    vector<int> v4 = {1, 1};
    std::cout << (solution.rob(v4) == 1) << std::endl;
    vector<int> v5 = {200, 3, 140, 20, 10};
    std::cout << (solution.rob(v5) == 340) << std::endl;

    return 0;
}