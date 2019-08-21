//#171 Excel Sheet Column Number - https://leetcode.com/problems/excel-sheet-column-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0, multiplier = 1;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            result += ((int)(s[i] - 'A') + 1) * multiplier;
            if(i != 0)
                multiplier *= 26;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "AB";
    int expected_answer = 28;
    assert(solution.titleToNumber(given_s) == expected_answer);

    given_s = "ZY";
    expected_answer = 701;
    assert(solution.titleToNumber(given_s) == expected_answer);

    return 0;
}
