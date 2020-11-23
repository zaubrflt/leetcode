/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

#include <string>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size(), result, carry = 0;
        string str = "";

        while (len1 != 0 || len2 != 0) {
            int value1 = (len1 != 0) ? a[--len1] - '0' : 0;
            int value2 = (len2 != 0) ? b[--len2] - '0' : 0;
            result = value1 + value2 + carry;
            carry = result / 2;
            str = ((result % 2 == 0) ? "0" : "1") + str;
        }
        return carry == 1 ? "1" + str : str;
    }
};