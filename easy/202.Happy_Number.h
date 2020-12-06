/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer,
replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/

#include <cmath>
#include <set>

using std::set;

class Solution1 {
public:
    bool isHappy(int n) {
        set<int> gotNums;

		while (n != 1 && gotNums.find(n) == gotNums.end()) {
			gotNums.insert(n);
			n = getNext(n);
		}

		return n == 1;
    }
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int tmp = n % 10;
            n = n / 10;
            sum += tmp * tmp;
        }
        return sum;
    }
};

// 快慢指针
class Solution2 {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int tmp = n % 10;
            n = n / 10;
            sum += tmp * tmp;
        }
        return sum;
    }
};