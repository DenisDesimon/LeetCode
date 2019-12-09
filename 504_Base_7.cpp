//#504 Base 7 - https://leetcode.com/problems/base-7/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string result;
        bool sign = num >= 0;
        num = abs(num);
        while(num)
        {
            result.insert(result.begin(), '0' + (num % 7));
            num /= 7;
        }
        return sign > 0 ? result : "-" + result;
    }
};

int main()
{
    Solution solution;
    int given_num = -7;
    string expected_answer = "-10";
    assert(solution.convertToBase7(given_num) == expected_answer);

    given_num = 100;
    expected_answer = "202";
    assert(solution.convertToBase7(given_num) == expected_answer);

    return 0;
}
