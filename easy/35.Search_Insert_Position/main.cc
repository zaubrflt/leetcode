#include <iostream>
#include <vector>
#include <algorithm>

#include "liblc.h"
#include "35.Search_Insert_Position.h"

using std::vector;


void test(Solution* solution, vector<int>& nums, int target)
{
    std::cout << "input: ";
    std::cout << nums << ", target = " << target << std::endl;

    int ret = solution->searchInsert(nums, target);

    nums.resize(ret);
    std::cout << "output: " << ret << std::endl;
}

int main(int argc, char const *argv[])
{
    {
        Solution solution;
        std::cout << "solution 1:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {1, 3, 5, 6};
        test(&solution, nums1, 5);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {1, 3, 5, 6};
        test(&solution, nums2, 2);
    
        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {1, 3, 5, 6};
        test(&solution, nums3, 7);

        std::cout << "test4:" << std::endl;
        vector<int> nums4 = {1, 3, 5, 6};
        test(&solution, nums4, 0);

        std::cout << "test5:" << std::endl;
        vector<int> nums5 = {1};
        test(&solution, nums4, 0);
    }

    return 0;
}