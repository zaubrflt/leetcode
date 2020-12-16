/*
Given an array nums, write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

#include <algorithm>
#include <vector>

using std::vector;

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, len = nums.size();
        while (left < len && right < len) {
            if (nums[left] != 0) {
                std::swap(nums[left], nums[right]);
                right++;
            }
            left++;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;

		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		for (int i = j; i < nums.size(); ++i) {
			nums[i] = 0;
		}
    }
};