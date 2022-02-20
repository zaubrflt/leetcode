#include <vector>

using std::vector;

class Solution {
public:
    virtual int removeElement(vector<int>&, int) = 0;
};

class Solution1 : public Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int i = 0;

        for (int j = 0; j < length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

class Solution2 : public Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int i = 0;

        while (i < length) {
            if (nums[i] == val) {
                nums[i] = nums[length - 1];
                length--;
            } else {
                i++;
            }
        }

        return length;
    }
};