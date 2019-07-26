//#12 Integer to Roman - https://leetcode.com/problems/integer-to-roman/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string decima[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string centum[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string quan[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string mile[10] = {"", "M", "MM", "MMM"};
        return mile[num / 1000] + quan[num / 100 % 10] + centum[num / 10 % 10] + decima[num % 10];
    }
};

int main()
{
    Solution solution;
    int given_num = 2345;
    string expected_answer = "MMCCCXLV";
    assert(solution.intToRoman(given_num) == expected_answer);

    given_num = 1994;
    expected_answer = "MCMXCIV";
    assert(solution.intToRoman(given_num) == expected_answer);

    return 0;
}
