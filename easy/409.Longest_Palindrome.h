/*
Given a string s which consists of lowercase or uppercase letters,
return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Example 3:

Input: s = "bb"
Output: 2

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> maps;
        for (int i = 0; i < s.size(); ++i) {
            maps[s[i]]++;
        }
        int cnt = 0;
        for (auto i = maps.begin(); i != maps.end(); ++i) {
            int v = (*i).second;
            cnt += v / 2 * 2;
            if ((cnt % 2 == 0) && (v % 2 == 1)) cnt += 1;
        }
        return cnt;
    }
};