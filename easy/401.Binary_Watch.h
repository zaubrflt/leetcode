/*
A binary watch has 4 LEDs on the top which represent the hours (0-11),
and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on,
return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

*/

#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> cnt;

        // 直接遍历 0:00 -> 12:00 每个时间有多少 1
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (count(i) + count(j) == num) {
                    cnt.push_back(std::to_string(i) + ":" +
                        (j < 10 ? "0" + std::to_string(j) : std::to_string(j)));
                }
            }
        }
        return cnt;
    }
private:
    // 计算二进制中 1 的个数
    int count(int n) {
        int cnt = 0;
        while (n != 0) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};