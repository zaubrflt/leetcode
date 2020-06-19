/*
1. Two Sum

Given an array of integers, return indices of the two numbers
such that they add up to a specific target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <vector>
#include <map>

using std::vector;
using std::map;

// twice hash
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> valueToIndex;

        for (int i = 0; i < nums.size(); ++i) {
            valueToIndex[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (valueToIndex.find(target - nums[i]) != valueToIndex.end() &&
                valueToIndex[target - nums[i]] != i) {
                    return vector<int>{i, valueToIndex[target - nums[i]]};
                }
        }
        return vector<int>{0, 0};
    }
};

// once hash
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> valueToIndex;

        for (int i = 0; i < nums.size(); ++i) {
            if (valueToIndex.find(target - nums[i]) != valueToIndex.end()) {
                // the value of 'valueToIndex[target - nums[i]]' will
                // always be smaller than 'i', just think why is that
                return vector<int>{valueToIndex[target - nums[i]], i};
            }
            valueToIndex[nums[i]] = i;
        }
        
        return vector<int>{0, 0};
    }
};