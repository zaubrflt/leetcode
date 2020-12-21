/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

 - What if the given array is already sorted? How would you optimize your algorithm?
 - What if nums1's size is small compared to nums2's size? Which algorithm is better?
 - What if elements of nums2 are stored on disk, and the memory is limited such that
   you cannot load all elements into the memory at once?

*/

#include <algorithm>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int>::iterator ite1 = nums1.begin();
        vector<int>::iterator ite2 = nums2.begin();
        while (ite1 != nums1.end() && ite2 != nums2.end()) {
            if (*ite1 == *ite2) {
                intersect.push_back(*ite1);
                ite1++; ite2++;
            } else if (*ite1 < *ite2) {
                ite1++;
            } else {
                ite2++;
            }
        }

        return intersect;
    }
};

class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) return intersect(nums2, nums1);

        map<int, int> counts;
        vector<int> intersect;

        for (auto i = nums2.begin(); i != nums2.end(); i++) {
            counts[*i]++;
        }

        for (auto i = nums1.begin(); i != nums1.end(); i++) {
            if (counts[*i]) {
                intersect.push_back(*i);
                counts[*i]--;
            }
        }

        return intersect;
    }
};