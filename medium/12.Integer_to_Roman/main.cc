#include "12.Integer_to_Roman.h"

#include <iostream>

int main(void)
{
    Solution1 solution1;
    std::cout << (solution1.intToRoman(3) == string("III")) << std::endl;
    std::cout << (solution1.intToRoman(4) == string("IV")) << std::endl;
    std::cout << (solution1.intToRoman(9) == string("IX")) << std::endl;
    std::cout << (solution1.intToRoman(58) == string("LVIII")) << std::endl;
    std::cout << (solution1.intToRoman(1994) == string("MCMXCIV")) << std::endl;

    Solution2 solution2;
    std::cout << (solution2.intToRoman(3) == string("III")) << std::endl;
    std::cout << (solution2.intToRoman(4) == string("IV")) << std::endl;
    std::cout << (solution2.intToRoman(9) == string("IX")) << std::endl;
    std::cout << (solution2.intToRoman(58) == string("LVIII")) << std::endl;
    std::cout << (solution2.intToRoman(1994) == string("MCMXCIV")) << std::endl;

    return 0;
}