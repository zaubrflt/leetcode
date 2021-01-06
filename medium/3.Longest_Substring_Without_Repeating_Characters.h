/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

#include <string>
#include <set>

using std::string;
using std::set;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        set<char> occurs;
        int n = s.size();

        int right = -1, max = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                occurs.erase(s[i - 1]);
            }
            while (right + 1 < n && !occurs.count(s[right + 1])) {
                occurs.insert(s[right + 1]);
                ++right;
            }
            max = std::max(max, right - i + 1);
        }
        return max;
    }
};