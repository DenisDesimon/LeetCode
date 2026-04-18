//#3783 Mirror Distance of an Integer - https://leetcode.com/problems/mirror-distance-of-an-integer/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int reversed = 0;
        int og = n;
        while(n)
        {
            reversed *= 10;
            reversed += n % 10;
            n /= 10;
        }
        return abs(og - reversed);
    }
};

int main()
{
    Solution solution;
    int givenN = 10;
    int expectedAnswer = 9;
    assert(solution.mirrorDistance(givenN) == expectedAnswer);

    givenN = 25;
    expectedAnswer = 27;
    assert(solution.mirrorDistance(givenN) == expectedAnswer);

    return 0;
}
