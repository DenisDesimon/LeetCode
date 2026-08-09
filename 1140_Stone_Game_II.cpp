//#1140 Stone Game II - https://leetcode.com/problems/stone-game-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    int n;
    int maxStones(int cur, int lastTake, vector<int> &suffix, vector<vector<int>> &memo)
    {
        if(cur + lastTake * 2 >= n)
            return suffix[cur];
        if(memo[cur][lastTake])
            return memo[cur][lastTake];
        int result = INT_MAX;
        for(int i = 1; i <= lastTake * 2; i++)
        {
            result = min(result, maxStones(cur + i, max(i, lastTake), suffix, memo));
        }
        return memo[cur][lastTake] = suffix[cur] - result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        vector<int> suffix = piles;
        for(int i = n -  2; i >= 0; i--)
            suffix[i] += suffix[i + 1];
        return maxStones(0, 1, suffix, memo);
    }
};

int main()
{
    Solution solution;
    vector<int> givenPiles = {2, 7, 9, 4, 4};
    int expectedAnswer = 10;
    assert(solution.stoneGameII(givenPiles) == expectedAnswer);

    givenPiles = {1, 2, 3, 4, 5, 100};
    expectedAnswer = 104;
    assert(solution.stoneGameII(givenPiles) == expectedAnswer);

    return 0;
}
