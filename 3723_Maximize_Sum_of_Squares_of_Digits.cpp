//#3723 Maximize Sum of Squares of Digits - https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9)
            return "";
        string result(sum / 9, '9');
        if(sum % 9)
            result += '0' + sum % 9;
        result.append(num - result.size(), '0');
        return result;
    }
};

int main()
{
    Solution solution;
    int givenNum  = 2;
    int givenSum = 3;
    string expectedAnswer = "30";
    assert(solution.maxSumOfSquares(givenNum, givenSum) == expectedAnswer);

    givenNum  = 2;
    givenSum = 17;
    expectedAnswer = "98";
    assert(solution.maxSumOfSquares(givenNum, givenSum) == expectedAnswer);

    return 0;
}
