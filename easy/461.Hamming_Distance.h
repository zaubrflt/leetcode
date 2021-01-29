/*
The Hamming distance between two integers is the number of positions
at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/

class Solution1 {
public:
    int hammingDistance(int x, int y) {
        x = x ^ y;
        int cnt = 0;
        while (x > 0) {
            if (x % 2 == 1) cnt++;
            x /= 2;
        }
        return cnt;
    }
};

class Solution2 {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int distance = 0;
        while (tmp != 0) {
            distance += 1;
            // remove the rightmost bit of '1'
            tmp = tmp & (tmp - 1);
        }
        return distance;
    }
};