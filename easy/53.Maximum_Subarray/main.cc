#include <iostream>
#include <vector>
#include <algorithm>

#include "liblc.h"
#include "53.Maximum_Subarray.h"

using std::vector;

void test(Solution* solution, vector<int>& nums)
{
    std::cout << "input: ";
    std::cout << nums << std::endl;

    int ret = solution->maxSubArray(nums);

    std::cout << "output: " << ret << std::endl;
}

int main(int argc, char const *argv[])
{
    {
        Solution1 solution;
        std::cout << "solution 1:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        test(&solution, nums1);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {1};
        test(&solution, nums2);
    
        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {5, 4, -1, 7, 8};
        test(&solution, nums3);
    }

    {
        Solution2 solution;
        std::cout << "solution 2:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        test(&solution, nums1);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {1};
        test(&solution, nums2);
    
        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {5, 4, -1, 7, 8};
        test(&solution, nums3);
    }

    return 0;
}