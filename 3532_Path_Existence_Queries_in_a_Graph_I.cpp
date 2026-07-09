//#3532 Path Existence Queries in a Graph I - https://leetcode.com/problems/path-existence-queries-in-a-graph-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    int find(int cur, vector<int> &parents)
    {
        if(parents[cur] == -1)
            return cur;
        return parents[cur] = find(parents[cur], parents);
    }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parents(n, -1);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i - 1] <= maxDiff)
            {
                int parentLeft = find(i - 1, parents);
                int parentRight = find(i, parents);
                if(parentLeft != parentRight)
                    parents[parentRight] = parentLeft;
            }
        }
        vector<bool> result;
        for(auto &query : queries)
        {
            if(find(query[0], parents) == find(query[1], parents))
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    vector<int> givenNums = {1, 3};
    int givenMaxDiff = 1;
    vector<vector<int>> givenQueries = {{0, 0}, {0, 1}};
    vector<bool> expectedAnswer = {true, false};
    assert(solution.pathExistenceQueries(givenN, givenNums, givenMaxDiff, givenQueries) == expectedAnswer);

    givenN = 4;
    givenNums = {2, 5, 6, 8};
    givenMaxDiff = 2;
    givenQueries = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    expectedAnswer = {false, false, true, true};
    assert(solution.pathExistenceQueries(givenN, givenNums, givenMaxDiff, givenQueries) == expectedAnswer);

    return 0;
}
