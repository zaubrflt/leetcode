#include <iostream>
#include <vector>

#include "liblc.h"
#include "26.Remove_Duplicates_from_Sorted_Array.h"

using std::vector;

void test(Solution* solution, vector<int>& nums)
{
    std::cout << "input: ";
    std::cout << nums << std::endl;

    int ret = solution->removeDuplicates(nums);

    nums.resize(ret);
    std::cout << "output: " << ret << ", nums = ";
    std::cout << nums << std::endl;
}

int main(int argc, char const *argv[])
{
    {
        Solution solution;
        std::cout << "solution 1:" << std::endl;

        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {1, 1, 2};
        test(&solution, nums1);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        test(&solution, nums2);
    }

    return 0;
}
