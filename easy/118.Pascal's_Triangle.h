/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = vector<vector<int>>();

        if (numRows == 0) {
            return triangle;
        }

        vector<int> tmp = { 1 };
        triangle.push_back(tmp);
        for (int i = 1; i < numRows; ++i) {
            vector<int> row = vector<int>();
            vector<int> preRow = triangle[i - 1];

            row.push_back(1);

            for (int j = 1; j < i; ++j) {
                row.push_back(preRow[j - 1] + preRow[j]);
            }

            row.push_back(1);
            triangle.push_back(row);
        }

        return triangle;
    }
};