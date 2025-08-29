//#3021 Alice and Bob Playing Flower Game - https://leetcode.com/problems/alice-and-bob-playing-flower-game/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long)n * m / 2;
    }
};

int main()
{
    Solution solution;
    int givenN = 58280;
    int givenM = 69389;
    long long expectedAnswer = 2021995460;
    assert(solution.flowerGame(givenN, givenM) == expectedAnswer);

    givenN = 24530;
    givenM = 80720;
    expectedAnswer = 990030800;
    assert(solution.flowerGame(givenN, givenM) == expectedAnswer);

    return 0;
}
