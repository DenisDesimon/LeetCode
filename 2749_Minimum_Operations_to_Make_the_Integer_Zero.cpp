//#2749 Minimum Operations to Make the Integer Zero - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int countOperations = 0;
        while(true)
        {
            long long sumOfPowers = num1 - (long long)num2 * countOperations;
            if(sumOfPowers < countOperations)
                break;
            if(__builtin_popcountll(sumOfPowers) <= countOperations)
                return countOperations;
            countOperations++;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int givenNum1 = 112577768;
    int givenNum2 = -501662198;
    int expectedAnswer = 16;
    assert(solution.makeTheIntegerZero(givenNum1, givenNum2) == expectedAnswer);

    givenNum1 = 112577768;
    givenNum2 = -501662198;
    expectedAnswer = 16;
    assert(solution.makeTheIntegerZero(givenNum1, givenNum2) == expectedAnswer);

    return 0;
}
