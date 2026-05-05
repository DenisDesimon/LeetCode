//#3919 Minimum Cost to Move Between Indices - https://leetcode.com/problems/minimum-cost-to-move-between-indices/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<long long> prefixRight(n), prefixLeft(n);
        for(int i = 0; i < n - 1; i++)
        {
            if(i == 0 || nums[i] - nums[i - 1] > nums[i + 1] - nums[i])
                prefixRight[i + 1] = prefixRight[i] + 1;
            else
                prefixRight[i + 1] = prefixRight[i] + nums[i + 1] - nums[i];
        }
        for(int i = 1; i < n; i++)
        {
            if(i == n - 1 || nums[i] - nums[i - 1] <= nums[i + 1] - nums[i])
                prefixLeft[i] = prefixLeft[i - 1] + 1;
            else
                prefixLeft[i] = prefixLeft[i - 1] + nums[i] - nums[i - 1];
        }
        vector<int> result;
        for(auto &query : queries)
        {
            if(query[0] < query[1])
                result.push_back(prefixRight[query[1]] - prefixRight[query[0]]);
            else
                result.push_back(prefixLeft[query[0]] - prefixLeft[query[1]]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {-5, -2, 3};
    vector<vector<int>> givenQueries = {{0, 2}, {2, 0}, {1, 2}};
    vector<int> expectedAnswer = {6, 2, 5};
    assert(solution.minCost(givenNums, givenQueries) == expectedAnswer);

    givenNums = {0, 2, 3, 9};
    givenQueries = {{3, 0}, {1, 2}, {2, 0}};
    expectedAnswer = {4, 1, 3};
    assert(solution.minCost(givenNums, givenQueries) == expectedAnswer);

    return 0;
}
