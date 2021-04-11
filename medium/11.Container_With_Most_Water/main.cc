#include "11.Container_With_Most_Water.h"

#include <iostream>

int main(void)
{
    Solution solution;

    std::vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << (solution.maxArea(v) == 49) << std::endl;

    std::vector<int> v1 = {1, 1};
    std::cout << (solution.maxArea(v1) == 1) << std::endl;

    std::vector<int> v2 = {4, 3, 2, 1, 4};
    std::cout << (solution.maxArea(v2) == 16) << std::endl;

    std::vector<int> v3 = {1, 2, 1};
    std::cout << (solution.maxArea(v3) == 2) << std::endl;

    std::vector<int> v4 = {1,3,2,5,25,24,5};
    std::cout << (solution.maxArea(v4) == 24) << std::endl;

    return 0;
}