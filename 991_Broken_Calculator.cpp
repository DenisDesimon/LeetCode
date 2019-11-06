//#991 Broken Calculator - https://leetcode.com/problems/broken-calculator/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        while(Y > X)
        {
            result++;
            if(Y % 2 == 1)
                Y--;
            else
                Y /= 2;
        }
        return result + X - Y;
    }
};

int main()
{
    Solution solution;
    int given_X = 5;
    int given_Y = 8;
    int expected_answer = 2;
    assert(solution.brokenCalc(given_X, given_Y) == expected_answer);

    given_X = 1024;
    given_Y = 1;
    expected_answer = 1023;
    assert(solution.brokenCalc(given_X, given_Y) == expected_answer);

    return 0;
}
