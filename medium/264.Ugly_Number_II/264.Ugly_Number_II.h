#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n + 1);
        nums[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        int num2, num3, num5;
        for (int i = 2; i <= n; ++i) {
            num2 = nums[p2] * 2;
            num3 = nums[p3] * 3;
            num5 = nums[p5] * 5;

            nums[i] = min(min(num2, num3), num5);
            if (num2 == nums[i]) p2++;
            if (num3 == nums[i]) p3++;
            if (num5 == nums[i]) p5++;
        }
        return nums[n];
    }
};