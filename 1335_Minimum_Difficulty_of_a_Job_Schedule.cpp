//#1335 Minimum Difficulty of a Job Schedule - https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > (int)jobDifficulty.size())
            return -1;
        vector<vector<int>> dp(d, vector<int>(jobDifficulty.size(), INT_MAX));
        int localMax = INT_MIN;
        for(int i = 0; i < (int)jobDifficulty.size(); i++)
        {
            localMax = max(localMax, jobDifficulty[i]);
            dp[0][i] = localMax;
        }
        for(int i = 0; i < d - 1; i++)
        {
            for(int j = i; j < (int)jobDifficulty.size() - 1; j++)
            {
                localMax = INT_MIN;
                for(int k = j + 1; k < (int)jobDifficulty.size(); k++)
                {
                    localMax = max(localMax, jobDifficulty[k]);
                    dp[i + 1][k] = min(dp[i + 1][k], localMax + dp[i][j]);
                }
            }
        }
        return dp.back().back();
    }
};

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();


int main()
{
    Solution solution;
    vector<int> given_jobDifficulty = {186, 398, 479, 206, 885, 423, 805, 112, 925, 656, 16, 932, 740, 292, 671, 360};
    int given_d = 4;
    int expected_answer = 1803;
    assert(solution.minDifficulty(given_jobDifficulty, given_d) == expected_answer);

    given_jobDifficulty = {6, 5, 4, 3, 2, 1};
    given_d = 2;
    expected_answer = 7;
    assert(solution.minDifficulty(given_jobDifficulty, given_d) == expected_answer);

    return 0;
}
