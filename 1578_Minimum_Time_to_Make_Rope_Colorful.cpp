//#1578 Minimum Time to Make Rope Colorful - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        char previousColor = colors.front();
        int previousTime = neededTime.front();
        for(int i = 1; i < (int)colors.size(); i++)
        {
            if(colors[i] == previousColor)
            {
                result = result + min(previousTime, neededTime[i]);
                previousTime = max(previousTime, neededTime[i]);
            }
            else
            {
                previousColor = colors[i];
                previousTime = neededTime[i];
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_colors = "aabaa";
    vector<int> given_time = {1, 2, 3, 4, 1};
    int expected_answer = 2;
    assert(solution.minCost(given_colors, given_time) == expected_answer);

    given_colors = "abaac";
    given_time = {1, 2, 3, 4, 5};
    expected_answer = 3;
    assert(solution.minCost(given_colors, given_time) == expected_answer);

    return 0;
}
