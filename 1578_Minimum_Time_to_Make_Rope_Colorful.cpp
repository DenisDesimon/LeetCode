//#1578 Minimum Time to Make Rope Colorful - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        for(int i = 1; i < (int)colors.size(); i++)
        {
            if(colors[i] == colors[i - 1])
            {
                result += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenColors = "aabaa";
    vector<int> givenTime = {1, 2, 3, 4, 1};
    int expectedAnswer = 2;
    assert(solution.minCost(givenColors, givenTime) == expectedAnswer);

    givenColors = "abaac";
    givenTime = {1, 2, 3, 4, 5};
    expectedAnswer = 3;
    assert(solution.minCost(givenColors, givenTime) == expectedAnswer);

    return 0;
}
