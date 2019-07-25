//#6 ZigZag Conversion - https://leetcode.com/problems/zigzag-conversion/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int cycle = numRows * 2 - 2;
        string result;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0;i + j < (int)s.size(); j += cycle)
            {
                result += s[i + j];
                if(i != 0 && i != numRows - 1 && j + cycle - i < (int)s.size())
                    result += s[j + cycle - i];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "a";
    int given_num = 1;
    string expected_answer = "a";
    assert(solution.convert(given_s, given_num) == expected_answer);

    given_s = "LEETCODEISHIRING";
    given_num = 3;
    expected_answer = "LCIRETOESIIGEDHN";
    assert(solution.convert(given_s, given_num) == expected_answer);

    return 0;
}
