//#2463 Minimum Total Distance Traveled - https://leetcode.com/problems/minimum-total-distance-traveled/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factoryPos;
        for(auto & fac : factory)
        {
            for(int i = 0; i < fac[1]; i++)
                factoryPos.push_back(fac[0]);
        }
        int n = robot.size();
        int m = factoryPos.size();
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1));
        for(int i = 0; i < n; i++)
            dp[i][m] = 1e12;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                dp[i][j] = abs(robot[i] - factoryPos[j]) + dp[i + 1][j + 1];
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }
        return dp.front().front();
    }
};

int main()
{
    Solution solution;
    vector<int> givenRobots = {0, 4, 6};
    vector<vector<int>> givenFactory = {{2, 2}, {6, 2}};
    long long expected_answer = 4;
    assert(solution.minimumTotalDistance(givenRobots, givenFactory) == expected_answer);

    givenRobots = {1, -1};
    givenFactory = {{-2, 1}, {2, 1}};
    expected_answer = 2;
    assert(solution.minimumTotalDistance(givenRobots, givenFactory) == expected_answer);

    return 0;
}
