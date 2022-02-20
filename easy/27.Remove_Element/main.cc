#include <iostream>
#include <vector>

#include "liblc.h"
#include "27.Remove_Element.h"

using std::vector;

void test(Solution* solution, vector<int>& nums, int val)
{
    std::cout << "input: ";
    std::cout << nums << ", val = " << val << std::endl;

    int ret = solution->removeElement(nums, val);

    nums.resize(ret);
    std::cout << "output: " << ret << ", nums = ";
    std::cout << nums << std::endl;
}

int main(int argc, char const *argv[])
{
    {
        Solution1 solution;
        std::cout << "solution 1:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {3, 2, 2, 3};
        test(&solution, nums1, 3);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
        test(&solution, nums2, 2);
    
        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {2};
        test(&solution, nums3, 3);

        std::cout << "test4:" << std::endl;
        vector<int> nums4 = {3, 3};
        test(&solution, nums4, 3);
    }

    {
        Solution2 solution;
        std::cout << "solution 2:" << std::endl;
        std::cout << "test1:" << std::endl;
        vector<int> nums1 = {3, 2, 2, 3};
        test(&solution, nums1, 3);

        std::cout << "test2:" << std::endl;
        vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
        test(&solution, nums2, 2);
    
        std::cout << "test3:" << std::endl;
        vector<int> nums3 = {2};
        test(&solution, nums3, 3);

        std::cout << "test4:" << std::endl;
        vector<int> nums4 = {3, 3};
        test(&solution, nums4, 3);
    }

    return 0;
}
