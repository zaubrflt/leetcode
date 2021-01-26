/*
You have a total of n coins that you want to form in a staircase shape,
where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.

Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/

#include <cmath>

class Solution1 {
public:
    int arrangeCoins(int n) {
        int sum = 0;

        for (int i = 1; i < n; ++i) {
            if (sum + i > n) break;
            sum += i;
        }
        return sum;
    }
};


/*
 x(x + 1) / 2 > n
 x^2 + x = 2n
 x^2 + x + 1/4 = 2n + 1/4
 (x + 1/2)^2 = 2n + 1/4
 x = sqrt(2n + 1/4) - 1/2
*/
class Solution2 {
public:
    int arrangeCoins(int n) {
        return int(sqrt(double(2 * (double)n + 0.25)) - 0.5);
    }
};