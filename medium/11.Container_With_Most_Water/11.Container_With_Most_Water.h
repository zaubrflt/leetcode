#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, tail = height.size() - 1;
        int maxAreaSize = 0;

        while (front < tail) {
            int tmp = min(height[front], height[tail]) * (tail - front);
            maxAreaSize = max(maxAreaSize, tmp);
            if (height[front] < height[tail]) {
                front++;
            } else {
                tail--;
            }
        }
        return maxAreaSize;
    }
};