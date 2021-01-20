/*
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Example 3:

Input: s = "a"
Output: "a"

Example 4:

Input: s = "ac"
Output: "a"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),

*/

#include <string>
#include <cmath>
#include <vector>

using namespace std;

// 动态规划
class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > dp(n, vector<int>(n));
        string ans;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i + k < n; ++i) {
                int j = i + k;
                if (k == 0) {
                    // 这里代表了所有长度为 1 的子串, 它们都是回文串
                    dp[i][j] = 1;
                } else if (k == 1) {
                    // 这里代表了所有长度为 2 的子串, 当两个字符相等, 则为回文串
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    // 长度大于等于 3 的子串, 如果头尾字符相等, 且去除头尾字符后的子串也是回文串, 则该串为回文串
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && k + 1 > ans.size()) {
                    ans = s.substr(i, k + 1);
                }
            }
        }
        return ans;
    }
};

// 中心扩散法
class Solution2 {
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 1) return "";
        if (s.size() == 1) return s;

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto odd = expandAroundCenter(s, i, i);
            auto even = expandAroundCenter(s, i, i + 1);

            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }
            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
private:
    pair<int, int> expandAroundCenter(string& s, int left, int right)
    {
        // left == right 时, 回文中心是一个字符, 回文串的长度是奇数
        // left + 1 == right 时, 回文中心是两个字符, 回文串的长度是偶数
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--; right++;
        }
        return {left + 1, right - 1};
    }
};