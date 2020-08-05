/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word (last word means the last appearing word if we loop from
left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1;

        while(end >= 0 && s[end] == ' ') end--;

        for (int i = end - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                return end - i;
            }
        }
        return end + 1;
    }
};