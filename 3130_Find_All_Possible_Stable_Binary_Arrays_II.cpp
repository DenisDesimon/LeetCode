//#3130 Find All Possible Stable Binary Arrays II - https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        vector<vector<int>> dpOne(zero + 1, vector<int> (one + 1));
        vector<vector<int>> dpZero(zero + 1, vector<int> (one + 1));
        vector<vector<int>> prefixOne(zero + 1, vector<int> (one + 1));
        vector<vector<int>> prefixZero(zero + 1, vector<int> (one + 1));
        for(int i = 1; i <= min(zero, limit); i++)
            dpZero[i][0] = prefixZero[i][0] = 1;
        for(int j = 1; j <= min(one, limit); j++)
            dpOne[0][j] = prefixOne[0][j] = 1;
        for(int i = 1; i <= zero; i++)
        {
            for(int j = 1; j <= one; j++)
            {
                dpZero[i][j] = prefixOne[i - 1][j];
                dpOne[i][j] = prefixZero[i][j - 1];
                if(i - limit - 1 >= 0)
                    dpZero[i][j] = (dpZero[i][j] - prefixOne[i - limit - 1][j] + mod) % mod;
                if(j - limit - 1 >= 0)
                    dpOne[i][j] = (dpOne[i][j] - prefixZero[i][j - limit - 1] + mod) % mod;
                prefixZero[i][j] = (prefixZero[i][j - 1] + dpZero[i][j]) % mod;
                prefixOne[i][j] = (prefixOne[i - 1][j] + dpOne[i][j]) % mod;
            }
        }
        return (dpOne.back().back() + dpZero.back().back()) % mod;
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
