//#3959 Check Good Integer - https://leetcode.com/problems/check-good-integer/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        long long squareSum = 0;
        while(n)
        {
            digitSum += n % 10;
            squareSum += (n % 10) * (n % 10);
            n /= 10;
        }
        return squareSum - digitSum >= 50;
    }
};

int main()
{
    Solution solution;
    int givenN = 1000;
    bool expectedAnswer = false;
    assert(solution.checkGoodInteger(givenN) == expectedAnswer);

    givenN = 19;
    expectedAnswer = true;
    assert(solution.checkGoodInteger(givenN) == expectedAnswer);

    return 0;
}
