/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

1. The length of both num1 and num2 is < 5100.
2. Both num1 and num2 contains only digits 0-9.
3. Both num1 and num2 does not contain any leading zero.
4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        string ans;
        while (i >= 0 || j >= 0) {
            int set1 = i < 0 ? 0 : num1[i] - '0';
            int set2 = j < 0 ? 0 : num2[j] - '0';
            int sum = set1 + set2 + carry;
            carry = sum / 10;
            ans.push_back((sum % 10) + '0');
            i--; j--;
        }
        if (carry == 1) ans = ans + "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};