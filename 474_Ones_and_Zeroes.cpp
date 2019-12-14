//#474 Ones and Zeroes - https://leetcode.com/problems/ones-and-zeroes/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(auto& str : strs)
        {
            int zeros = count(str.begin(), str.end(), '0'), ones = str.size() - zeros;
            for(int i = m; i >= 0; i--)
            {
                for(int j = n; j >= 0; j--)
                {
                    if(i >= zeros && j >= ones)
                        dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    vector<string> given_str = {"10", "0001", "111001", "1", "0"};
    int given_m = 5;
    int given_n = 4;
    int expected_answer = 4;
    assert(solution.findMaxForm(given_str, given_m, given_n) == expected_answer);

    given_str = {"111", "1000", "1000", "1000"};
    given_m = 9;
    given_n = 3;
    expected_answer = 3;
    assert(solution.findMaxForm(given_str, given_m, given_n) == expected_answer);

    return 0;
}
