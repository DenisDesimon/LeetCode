//#3534 Path Existence Queries in a Graph II - https://leetcode.com/problems/path-existence-queries-in-a-graph-ii/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> sortedNums(n);
        for(int i = 0; i < n; i++)
            sortedNums[i] = {nums[i], i};
        sort(sortedNums.begin(), sortedNums.end());
        vector<int> idxInSorted(n);
        vector<int> result(queries.size());
        for(int i = 0; i < n; i++)
        {
            idxInSorted[sortedNums[i].second] = i;
        }
        int m = 18;
        vector<vector<int>> farestNode(n, vector<int>(m));
        for(int left = 0, right = 0; left < n; left++)
        {
            if(right < left)
                right = left;
            while(right + 1 < n && sortedNums[right + 1].first - sortedNums[right].first <= maxDiff &&
                  sortedNums[right + 1].first - sortedNums[left].first <= maxDiff)
                right++;
            farestNode[left][0] = right;
        }
        for(int j = 1; j < m; j++)
        {
            for(int i = 0; i < n; i++)
            {
                farestNode[i][j] = farestNode[farestNode[i][j - 1]][j - 1];
            }
        }
        for(int i = 0; i < (int)queries.size(); i++)
        {
            int left = idxInSorted[queries[i][0]];
            int right = idxInSorted[queries[i][1]];
            if(left > right)
                swap(left, right);
            if(left == right)
                continue;
            int cur = left;
            int steps = 0;
            for(int jump = m - 1; jump >= 0; jump--)
            {
                if(farestNode[cur][jump] < right)
                {
                    cur = farestNode[cur][jump];
                    steps += (1 << jump);
                }
            }
            result[i] = farestNode[cur][0] >= right ? steps + 1 : -1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 5;
    vector<int> givenNums = {1, 8, 3, 4, 2};
    int givenMaxDiff = 3;
    vector<vector<int>> givenQueries = {{0, 3}, {2, 4}};
    vector<int> expectedAnswer = {1, 1};
    assert(solution.pathExistenceQueries(givenN, givenNums, givenMaxDiff, givenQueries) == expectedAnswer);

    givenN = 5;
    givenNums = {5, 3, 1, 9, 10};
    givenMaxDiff = 2;
    givenQueries = {{0, 1}, {0, 2}, {2, 3}, {4, 3}};
    expectedAnswer = {1, 2, -1, 1};
    assert(solution.pathExistenceQueries(givenN, givenNums, givenMaxDiff, givenQueries) == expectedAnswer);

    return 0;
}
