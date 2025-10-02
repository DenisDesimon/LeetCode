//#3100 Water Bottles II - https://leetcode.com/problems/water-bottles-ii/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        double b = -3 + 2 * numExchange;
        double c = -2 * numBottles;
        double disc = b * b - 4 * c;
        int timesEx = ceil((-b + sqrt(disc)) / 2) - 1;
        return numBottles + timesEx;
    }
};

int main()
{
    Solution solution;
    int givenNumBottles = 10;
    int givenNumExchange = 3;
    int expectedAnswer = 13;
    assert(solution.maxBottlesDrunk(givenNumBottles, givenNumExchange) == expectedAnswer);

    givenNumBottles = 1;
    givenNumExchange = 2;
    expectedAnswer = 1;
    assert(solution.maxBottlesDrunk(givenNumBottles, givenNumExchange) == expectedAnswer);

    return 0;
}
