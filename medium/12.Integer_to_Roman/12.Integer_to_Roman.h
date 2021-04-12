#include <string>
#include <vector>
#include <map>

using namespace std;

// for solution 1

const vector<int>    values  = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};    
const vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

class Solution1 {
public:
    string intToRoman(int num) {
        string ans = "";

        for (int i = 0; i < values.size() && num >= 0; i++) {
            while (values[i] <= num) {
                num -= values[i];
                ans += symbols[i];
            }
        }
        return ans;
    }
};

// for solution 2

const vector<string> thousands = {"", "M", "MM", "MMM"};
const vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
const vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution2 {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};