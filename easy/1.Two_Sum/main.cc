#include <iostream>
#include <vector>

#include "liblc.h"
#include "1.Two_Sum.h"

using std::vector;

void test(Solution* solution, vector<int>& nums, int target)
{
    std::cout << "input: ";
    std::cout << nums << std::endl;

    vector<int> ret = solution->twoSum(nums, target);

    std::cout << "output: ";
    std::cout << ret << std::endl;
}

int main(int argc, char const *argv[])
{
    {
        Solution1 solution;
        std::cout << "solution 1:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {2, 7, 11, 15};
        test(&solution, nums1, 9);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {3, 2, 4};
        test(&solution, nums2, 6);

        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {3, 3};
        test(&solution, nums3, 6);
    }

    {
        Solution2 solution;
        std::cout << "solution 2:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {2, 7, 11, 15};
        test(&solution, nums1, 9);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {3, 2, 4};
        test(&solution, nums2, 6);

        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {3, 3};
        test(&solution, nums3, 6);
    }
    return 0;
}
