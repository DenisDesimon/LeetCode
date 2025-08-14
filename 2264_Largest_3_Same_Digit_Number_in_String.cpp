//#2264 Largest 3-Same-Digit Number in String - https://leetcode.com/problems/largest-3-same-digit-number-in-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        char result = '/';
        for(int i = 2; i < (int)num.size(); i++)
        {
            if(num[i - 2] == num[i] && num[i - 1] == num[i])
                result = max(result, num[i]);
        }
        return result == '/' ? "" : string(3, result);
    }
};

int main()
{
    Solution solution;
    string givenNum = "6777133339";
    string expectedAnswer = "777";
    assert(solution.largestGoodInteger(givenNum) == expectedAnswer);

    givenNum = "2300019";
    expectedAnswer = "000";
    assert(solution.largestGoodInteger(givenNum) == expectedAnswer);

    return 0;
}
