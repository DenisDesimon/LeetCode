//#357 Count Numbers with Unique Digits - https://leetcode.com/problems/count-numbers-with-unique-digits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int result = 10, sub_result = 9;
        for(int i = 2; i <= n; i++)
        {
            sub_result *= (11 - i);
            result += sub_result;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    int expected_answer = 739;
    assert(solution.countNumbersWithUniqueDigits(given_n) == expected_answer);

    given_n = 4;
    expected_answer = 5275;
    assert(solution.countNumbersWithUniqueDigits(given_n) == expected_answer);

    return 0;
}
