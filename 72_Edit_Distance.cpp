//#72 Edit Distance - https://leetcode.com/problems/edit-distance/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
//solve with recursion
    int distance(int x, int y, vector<vector<bool>>& ready, vector<vector<int>>& value, string word1, string word2){
        if(x < 0 || y < 0)
            return 1e9;
        if(x == 0 && y == 0)
            return 0;
        if(ready[x][y])
            return value[x][y];
        int best = min({distance(x, y - 1, ready, value, word1, word2) + 1,
                   distance(x - 1, y, ready, value, word1, word2) + 1,
                   distance(x - 1,y - 1, ready, value, word1, word2) + (word1[x - 1] == word2[y - 1] ? 0 : 1) });
        value[x][y] = best;
        ready[x][y] = true;
        return best;
    }
public:
    int minDistanceRecursion(string word1, string word2) {
        vector<vector<bool>> ready(word1.size() + 1, vector<bool>  (word2.size() + 1, false));
        vector<vector<int>> value(word1.size() + 1, vector<int>  (word2.size() + 1, 0));
        return distance(word1.size(), word2.size(), ready, value, word1, word2);

    }
    int minDistance(string word1, string word2) {
        int x = word1.size(), y = word2.size();
        vector<vector<int>> dp(x + 1, vector<int> (y + 1, 0));
        for(int i = 1; i <= x; i++)
            dp[i][0] = i;
        for(int j = 1; j <= y; j++)
            dp[0][j] = j;

        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y ; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j -1];
                else
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
        return dp[x][y];
        }

};

int main()
{
    Solution solution;
    string given_word1 = "blocked";
    string given_word2 = "lol";
    int  expected_answer = 5;
    assert(solution.minDistance(given_word1, given_word2) == expected_answer);
    assert(solution.minDistanceRecursion(given_word1, given_word2) == expected_answer);

    given_word1 = "horse";
    given_word2 = "ros";
    expected_answer = 3;
    assert(solution.minDistance(given_word1, given_word2) == expected_answer);
    assert(solution.minDistanceRecursion(given_word1, given_word2) == expected_answer);

    return 0;
}
