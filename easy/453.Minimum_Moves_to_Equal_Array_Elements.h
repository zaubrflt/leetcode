/*
Given a non-empty integer array of size n,
find the minimum number of moves required to make all array elements equal,
where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

*/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution1 {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;
    }
};

class Solution2 {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for (int i = 1; i < nums.size(); i++) {
            int diff = (moves + nums[i]) - nums[i - 1];
            nums[i] += moves;
            moves += diff;
        }
        return moves;
    }
};

// 将 n - 1 个数减为最小值
class Solution3 {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0, min = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            min = std::min(min, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            moves += nums[i] - min;
        }
        return moves;
    }
};