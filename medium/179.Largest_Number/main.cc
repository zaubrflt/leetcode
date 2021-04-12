#include "179.Largest_Number.h"

#include <iostream>

int main(void)
{
    Solution solution;
    vector<int> v;

    v = {10, 2};
    std::cout << (solution.largestNumber(v) == "210") << std::endl;

    v = {3, 30, 34, 5, 9};
    std::cout << (solution.largestNumber(v) == "9534330") << std::endl;
    
    v = {1};
    std::cout << (solution.largestNumber(v) == "1") << std::endl;

    v = {10};
    std::cout << (solution.largestNumber(v) == "10") << std::endl;

    v = {0, 0};
    std::cout << (solution.largestNumber(v) == "0") << std::endl;

    return 0;
}