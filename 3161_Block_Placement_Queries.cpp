//#3161 Block Placement Queries - https://leetcode.com/problems/block-placement-queries/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    vector<int> segment;
    void update(int R, int val, int p, int l, int r)
    {
        if(l == r)
        {
            segment[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(R <= mid)
            update(R, val, p << 1, l, mid);
        else
            update(R, val, p << 1 | 1, mid + 1, r);
        segment[p] = max(segment[p << 1], segment[p << 1 | 1]);
    }
    int query(int L, int R, int p, int l, int r)
    {
        if(L <= l && r <= R)
            return segment[p];
        int mid = (l + r) >> 1;
        int result = 0;
        if(L <= mid)
            result = query(L, R, p << 1, l, mid);
        if(R > mid)
            result = max(result, query(L, R, p << 1 | 1, mid + 1, r));
        return result;
    }
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int maxLen = 5e4;
        segment.resize(maxLen << 2);
        set<int> obstacles = {0, maxLen};
        update(maxLen, maxLen, 1, 0, maxLen);
        vector<bool> result;
        for(auto &q : queries)
        {
            if(q[0] == 1)
            {
                int x = q[1];
                auto it = obstacles.upper_bound(x);
                int R = *it;
                int L = *prev(it);
                update(x, x - L, 1, 0, maxLen);
                update(R, R - x, 1, 0, maxLen);
                obstacles.insert(x);
            }
            else
            {
                int x = q[1];
                int len = q[2];
                auto it = obstacles.upper_bound(x);
                it--;
                int pre = *it;
                int maxSpace = query(0, pre, 1, 0, maxLen);
                maxSpace = max(maxSpace, x - pre);
                result.push_back(maxSpace >= len);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenQueries = {{1, 2}, {2, 3, 3}, {2 ,3, 1} ,{2, 2, 2}};
    vector<bool> expectedAnswer = {false, true, true};
    assert(solution.getResults(givenQueries) == expectedAnswer);

    givenQueries = {{1, 7} ,{2, 7, 6}, {1, 2}, {2, 7, 5} ,{2, 7, 6}};
    expectedAnswer = {true, true, false};
    assert(solution.getResults(givenQueries) == expectedAnswer);

    return 0;
}
