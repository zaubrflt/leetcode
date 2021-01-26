/*
You are given a string s, return the number of segments in the string. 

A segment is defined to be a contiguous sequence of non-space characters.

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

Example 2:

Input: s = "Hello"
Output: 1

Example 3:

Input: s = "love live! mu'sic forever"
Output: 4

Example 4:

Input: s = ""
Output: 0

Constraints:

0 <= s.length <= 300
s consists of lower-case and upper-case English letters,
digits or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.

*/

#include <string>

using namespace std;

class Solution1 {
public:
    int countSegments(string s) {
        bool flag = false;
        int cnt = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && flag == true) {
                flag = false;
                cnt++;
            } else flag = true;
        }
        return cnt;
    }
};

class Solution2 {
public:
    int countSegments(string s) {
        int segmentCount = 0;

        for (int i = 0; i < s.size(); ++i) {
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }
};