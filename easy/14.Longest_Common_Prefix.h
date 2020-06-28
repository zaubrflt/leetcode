/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.

*/

#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int count = strs.size();
        string prefix = strs[0];
        for (int i = 1; i < count; ++i) {
            prefix = getLongestCommonPrefix(prefix, strs[i]);
            if (prefix.size() == 0) break;
        }
        return prefix;
    }

private:
    string getLongestCommonPrefix(const string& lhs, const string& rhs) {
        int length = std::min(lhs.size(), rhs.size());
        int index = 0;
        while (index < length && lhs[index] == rhs[index]) {
            ++index;
        }
        return lhs.substr(0, index);
    }
};

class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int length = strs[0].size();
        int count = strs.size();
        char c;
        for (int i = 0; i < length; ++i) {
            c = strs[0][i];
            for (int j = 1; j < count; ++j) {
                if (strs[j][i] != c || i == strs[j].size()) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

class Solution3 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        else {
            return getLongestComPre(strs, 0, strs.size() - 1);
        }
    }
private:
    string getLongestComPre(const vector<string>& strs, int start, int end) {
        if (start == end) return strs[start];
        else {
            int mid = (start + end) / 2;
            string lcpLeft = getLongestComPre(strs, start, mid);
            string lcpRight = getLongestComPre(strs, mid + 1, end);
            return getComPre(lcpLeft, lcpRight);
        }
    }

    string getComPre(const string& lhs, const string& rhs) {
        int length = std::min(lhs.size(), rhs.size());
        int index = 0;
        while (index < length && lhs[index] == rhs[index]) {
            ++index;
        }
        return lhs.substr(0, index);
    }
};

class Solution4 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int minLength = std::min_element(strs.begin(), strs.end(),
            [](const string& lhs, const string& rhs)
            { return lhs.size() < rhs.size(); })->size();
        int low = 0, high = minLength, mid;
        while (low < high) {
            mid = (high - low + 1) / 2 + low;
            if (isCommonPrefix(strs, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }

private:
    bool isCommonPrefix(const vector<string>& strs, int length) {
        string str0 = strs[0].substr(0, length), str;
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            if (str0 != strs[i].substr(0, length)) {
                return false;
            }
        }
        return true;
    }
};