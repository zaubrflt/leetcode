/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    bool isValid(string s) {
        int length = s.size();
        vector<char> stack;
        for (int i = 0; i < length; ++i) {
            if (isLeftParentheses(s[i])) {
                stack.push_back(s[i]);
            } else if (stack.size() == 0) {
                return false;
            } else if (isMatch(stack[stack.size() - 1], s[i]) == false) {
                return false;
            } else {
                stack.pop_back();
            }
        }
        return stack.size() == 0 ? true : false;
    }
private:
    bool isLeftParentheses(const char& ch) {
        return (ch == '(' || ch == '{' || ch == '[') ? true : false;
    }

    bool isMatch(const char& lhs, const char& rhs) {
        if (lhs == '(' && rhs == ')') return true;
        else if (lhs == '[' && rhs == ']') return true;
        else if (lhs == '{' && rhs == '}') return true;
        else return false;
    }
};