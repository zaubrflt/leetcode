/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

*/

#include <algorithm>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;
        for (auto& num : nums1) {
            set1.insert(num);
        }
        for (auto& num : nums2) {
            set2.insert(num);
        }
        return getIntersection(set1, set2);
    }
private:
    vector<int> getIntersection(set<int>& set1, set<int>& set2) {
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1);
        }
        vector<int> intersection;
        for (auto& num : set1) {
            if (set2.count(num)) {
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int>::iterator ite1 = nums1.begin(), ite2 = nums2.begin();
        vector<int> intersection;
        while (ite1 != nums1.end() && ite2 != nums2.end()) {
            if (*ite1 == *ite2) {
                if (!intersection.size() || *ite1 != intersection.back()) {
                    intersection.push_back(*ite1);
                }
                ite1++; ite2++;
            } else if (*ite1 < *ite2) {
                ite1++;
            } else {
                ite2++;
            }
        }
        return intersection;
    }
};