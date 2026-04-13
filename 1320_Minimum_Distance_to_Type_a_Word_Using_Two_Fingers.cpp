//#1320 Minimum Distance to Type a Word Using Two Fingers - https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    int distance(int start, int end){
        return abs(start / 6 - end / 6) + abs(start % 6 - end % 6);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        int dp[n][26][26];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                fill(dp[i][j], dp[i][j] + 26, INT_MAX >> 1);
            }
        }
        for(int i = 0; i < 26; i++)
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        for(int i = 1; i < n; i++)
        {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            int d = distance(cur, prev);
            for(int j = 0; j < 26; j++)
            {
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                if(prev == j)
                {
                    for(int k = 0; k < 26; k++)
                    {
                        int d0 = distance(k, cur);
                        dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][k][j] + d0);
                        dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][k] + d0);
                    }
                }
            }
        }
        int result = INT_MAX >> 2;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
                result = min(result, dp[n - 1][i][j]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "CAKE";
    int expected_answer = 3;
    assert(solution.minimumDistance(givenS) == expected_answer);

    givenS = "HAPPY";
    expected_answer = 6;
    assert(solution.minimumDistance(givenS) == expected_answer);

    return 0;
}
