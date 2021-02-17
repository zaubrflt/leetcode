/*
You are given a license key represented as a string result which consists only alphanumeric character and dashes.
The string is separated into N+1 groups by N dashes.

Given a number K, we would want to reformat the strings such that each group contains exactly K characters,
except for the first group which could be shorter than K, but still must contain at least one character. Furthermore,
there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.

Given a non-empty string result and a number K, format the string according to the rules described above.

Example 1:
Input: result = "5F3Z-2e-9-w", K = 4

Output: "5F3Z-2E9W"

Explanation: The string result has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.

Example 2:
Input: result = "2-5g-3-J", K = 2

Output: "2-5G-3J"

Explanation: The string result has been split into three parts, each part has 2 characters except
the first part as it could be shorter as mentioned above.

Note:
1. The length of string result will not exceed 12,000, and K is a positive integer.
2. String result consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
3. String result is non-empty.

*/

#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result = "";
        int count = 0;
        for (int i = S.size() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (count != 0 && count % K == 0) {
                    result.push_back('-');
                }
                result.push_back(toUpper(S[i]));
                count++;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
private:
    char toUpper(char c) {
        return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
    }
};