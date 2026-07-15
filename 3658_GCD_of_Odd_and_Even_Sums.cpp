//#3658 GCD of Odd and Even Sums - https://leetcode.com/problems/gcd-of-odd-and-even-sums/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = (1 + n) * n, sumEven = n * n;
        while(sumEven != 0)
        {
            int temp = sumEven;
            sumEven = sumOdd % sumEven;
            sumOdd = temp;
        }
        return sumOdd;
    }
};

int main()
{
    Solution solution;
    int givenN = 4;
    int expectedAnswer = 4;
    assert(solution.gcdOfOddEvenSums(givenN) == expectedAnswer);

    givenN = 5;
    expectedAnswer = 5;
    assert(solution.gcdOfOddEvenSums(givenN) == expectedAnswer);

    return 0;
}
