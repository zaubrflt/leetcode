#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            string strA = to_string(a);
            string strB = to_string(b);
            return strA + strB > strB + strA;
        });

        if (nums[0] == 0) {
            return "0";
        }

        string ans;
        for (int i = 0; i < nums.size(); ++i) {
            ans += to_string(nums[i]);
        }
        return ans;
    }
};