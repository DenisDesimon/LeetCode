//#1569 Number of Ways to Reorder Array to Get Same BST - https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
    vector<vector<long long>> pascalTriangle;
    long long MOD = 1e9 + 7;
    long long dfs(vector<int> nums){
        int n = nums.size();
        if(n < 3)
            return 1;
        vector<int> leftNodes, rightNodes;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < nums[0])
                leftNodes.push_back(nums[i]);
            else
                rightNodes.push_back(nums[i]);
        }
        long long leftWays = dfs(leftNodes) % MOD;
        long long rightWays = dfs(rightNodes) % MOD;
        return (((leftWays * rightWays) % MOD) * pascalTriangle[n - 1][leftNodes.size()]) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascalTriangle.resize(n + 1);
        for(int i = 0; i < n; i++)
        {
            pascalTriangle[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; j++)
            {
                pascalTriangle[i][j] = (pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]) % MOD;
            }
        }
        return (dfs(nums) - 1) % MOD;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {2, 1, 3};
    int expectedAnswer = 1;
    assert(solution.numOfWays(givenNums) == expectedAnswer);

    givenNums  = {3, 4, 5, 1, 2};
    expectedAnswer = 5;
    assert(solution.numOfWays(givenNums) == expectedAnswer);

    return 0;
}
