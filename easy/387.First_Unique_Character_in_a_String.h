/*
Given a string, find the first non-repeating character in it and return its index.
If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.

Note: You may assume the string contains only lowercase English letters.

*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counts = vector<int>(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            counts[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (counts[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};