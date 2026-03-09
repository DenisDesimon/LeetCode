//#3129 Find All Possible Stable Binary Arrays I - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1));
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1));
        for(int i = 1; i <= min(zero, limit); i++)
            dp0[i][0] = 1;
        for(int j = 1; j <= min(one, limit); j++)
            dp1[0][j] = 1;
        for(int i = 1; i <= zero; i++)
        {
            for(int j = 1; j <= one; j++)
            {
                for(int k = 1; k <= min(limit, i); k++)
                    dp0[i][j] = (dp0[i][j] + dp1[i - k][j]) % mod;
                for(int k = 1; k <= min(limit, j); k++)
                    dp1[i][j] = (dp1[i][j] + dp0[i][j - k]) % mod;
            }
        }
        return (dp0.back().back() + dp1.back().back()) % mod;
    }
};

int main()
{
    Solution solution;
    int givenZero = 1;
    int givenOne = 1;
    int givenLimit = 2;
    int expectedAnswer = 2;
    assert(solution.numberOfStableArrays(givenZero, givenOne, givenLimit) == expectedAnswer);

    givenZero = 3;
    givenOne = 3;
    givenLimit = 2;
    expectedAnswer = 14;
    assert(solution.numberOfStableArrays(givenZero, givenOne, givenLimit) == expectedAnswer);

    return 0;
}
