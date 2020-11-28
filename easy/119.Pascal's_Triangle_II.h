/*
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:

Input: rowIndex = 0
Output: [1]

Example 3:

Input: rowIndex = 1
Output: [1,1]

Constraints:

0 <= rowIndex <= 40

     [1,0,0,0],
    [1,1,0,0],
   [1,2,1,0],
  [1,3,3,1],

*/

#include <vector>

using std::vector;

class Solution1 {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int>({1});
        vector<int> arr(rowIndex + 1);
        arr[0] = 1;
        for (int i = 1; i <= rowIndex; i++)
            arr[i] = (unsigned long)arr[i - 1] * (unsigned long)(rowIndex - i + 1) / i;
        return arr;
    }
};

class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i = 0; i < rowIndex + 1; ++i){
            result.push_back(1);
            for(int j = i - 1; j > 0; --j){
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};