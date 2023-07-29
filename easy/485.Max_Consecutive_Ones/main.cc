#include "485.Max_Consecutive_Ones.h"

#include <iostream>

int main (int argc, char *argv[]) {
    {
        Solution solution;

        std::vector<int> nums{1,1,0,1,1,1};

        std::cout << solution.findMaxConsecutiveOnes(nums) << std::endl;
    }
    {
        Solution solution;

        std::vector<int> nums{1,0,1,1,0,1};

        std::cout << solution.findMaxConsecutiveOnes(nums) << std::endl;
    }


    return 0;
}
