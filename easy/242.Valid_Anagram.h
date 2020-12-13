/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> table(LOW_LET_CNT, 0);
        for (int i = 0; i < s.size(); ++i) {
            table[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            table[t[i] - 'a']--;
            if (table[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
private:
    const int LOW_LET_CNT = 26;
};