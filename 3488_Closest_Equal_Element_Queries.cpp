//#3488 Closest Equal Element Queries - https://leetcode.com/problems/closest-equal-element-queries/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> numPos;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            numPos[nums[i]].push_back(i);
        vector<int> result;
        for(auto &query : queries)
        {
            if(numPos[nums[query]].size() == 1)
            {
                result.push_back(-1);
                continue;
            }
            int pos = lower_bound(numPos[nums[query]].begin(), numPos[nums[query]].end(), query) - numPos[nums[query]].begin();
            int right, left;
            if(pos != (int)numPos[nums[query]].size() - 1)
                right = numPos[nums[query]][pos + 1] - query;
            else
                right = n - query + *(numPos[nums[query]].begin());
            if(pos == 0)
                left = query + (n - *(numPos[nums[query]].rbegin()));
            else
                left = query - numPos[nums[query]][pos - 1];
            result.push_back(min(left, right));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 1, 4, 1, 3, 2};
    vector<int> givenQueris = {0, 3, 5};
    vector<int> expectedAnswer = {2, -1, 3};
    assert(solution.solveQueries(givenNums, givenQueris) == expectedAnswer);

    givenNums = {1, 2, 3, 4};
    givenQueris = {0, 1, 2, 3};
    expectedAnswer = {-1, -1, -1, -1};
    assert(solution.solveQueries(givenNums, givenQueris) == expectedAnswer);

    return 0;
}
