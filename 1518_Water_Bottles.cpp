//#1518 Water Bottles - https://leetcode.com/problems/water-bottles/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles;
        while(numBottles / numExchange)
        {
            result += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenNumBottles = 9;
    int givenNumExchange = 3;
    int expectedAnswer = 13;
    assert(solution.numWaterBottles(givenNumBottles, givenNumExchange) == expectedAnswer);

    givenNumBottles = 15;
    givenNumExchange = 4;
    expectedAnswer = 19;
    assert(solution.numWaterBottles(givenNumBottles, givenNumExchange) == expectedAnswer);

    return 0;
}
