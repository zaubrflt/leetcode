/*
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority, cnt = 0;

        for (int num : nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
		int majority = nums[0];
		int length = nums.size();

		for (int i = 1; i < length; i++) {
			if (count == 0) {
				majority = nums[i];
				count++;
			} else if (majority == nums[i]) {
				count++;
			} else if (majority != nums[i]) {
				count--;
			}
		}

		return majority;
    }
};