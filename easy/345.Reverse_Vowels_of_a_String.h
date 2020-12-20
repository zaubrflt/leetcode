/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".

*/

#include <string>

using std::string;

class Solution {
public:
    string reverseVowels(string s) {
        string tmp = s;
        int n = tmp.size();
        for (int left = 0, right = n - 1; left < right; ) {
            if (isVowel(tmp[left]) && isVowel(tmp[right])) {
                std::swap(tmp[left], tmp[right]);
                ++left; --right;
            } else if (!isVowel(tmp[left])) {
                ++left;
            } else {
                --right;
            }
        }
        return tmp;
    }
private:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }
};