//#3954 Sum of Compatible Numbers in Range I - https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        for(int i = max(1, n - k); i <= n + k; i++)
        {
            if((i & n) == 0)
                sum += i;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    int givenK = 3;
    int expectedAnswer = 10;
    assert(solution.sumOfGoodIntegers(givenN, givenK) == expectedAnswer);

    givenN = 5;
    givenK = 1;
    expectedAnswer = 0;
    assert(solution.sumOfGoodIntegers(givenN, givenK) == expectedAnswer);

    return 0;
}
