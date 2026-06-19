//#1732 Find the Highest Altitude - https://leetcode.com/problems/find-the-highest-altitude/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int cur = 0;
        for(auto &step : gain)
        {
            cur += step;
            result = max(result, cur);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenGain = {-5, 1, 5, 0, -7};
    char expectedAnswer = 1;
    assert(solution.largestAltitude(givenGain) == expectedAnswer);

    givenGain = {-4, -3, -2, -1, 4, 3, 2};
    expectedAnswer = 0;
    assert(solution.largestAltitude(givenGain) == expectedAnswer);

    return 0;
}
