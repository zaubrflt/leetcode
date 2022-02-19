#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    virtual vector<int> twoSum(vector<int>&, int) = 0;
};

// twice hash
class Solution1 : public Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;

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
class Solution2 : public Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex;

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