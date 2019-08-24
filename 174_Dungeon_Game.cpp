//#174 Dungeon Game - https://leetcode.com/problems/dungeon-game/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 1;
        int n = dungeon.size(), m = dungeon[0].size();
        vector<int> dp(m + 1, INT_MAX);
        dp[m - 1] = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
        }
        return dp[0];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_dungeon = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    int expected_answer = 3;
    assert(solution.calculateMinimumHP(given_dungeon) == expected_answer);

    given_dungeon = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    expected_answer = 3;
    assert(solution.calculateMinimumHP(given_dungeon) == expected_answer);

    return 0;
}
