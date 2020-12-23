/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines;
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

You may assume that both strings contain only lowercase letters.

*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.length() < ransomNote.length()) return false;

        vector<int> counts = vector<int>(26, 0);
        for (int i = 0; i < magazine.size(); ++i) {
            counts[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ransomNote.size(); ++i) {
            if (counts[ransomNote[i] - 'a'] > 0) counts[ransomNote[i] - 'a']--;
            else {
                return false;
            }
        }
        return true;
    }
};