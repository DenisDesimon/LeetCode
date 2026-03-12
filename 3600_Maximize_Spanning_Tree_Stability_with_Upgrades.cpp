//#3600 Maximize Spanning Tree Stability with Upgrades - https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int find(int cur, vector<int> &parent)
    {
        return parent[cur] < 0 ? cur : parent[cur] = find(parent[cur], parent);
    }
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<array<int, 3>> optional;
        vector<int> parent(n, - 1);
        int countEdges = 0, minMust = 2e5, minSingle = 2e5, minDouble = 1e5;
        for(auto &edge : edges)
        {
            if(edge[3])
            {
                int parentLeft = find(edge[0], parent);
                int parentRight = find(edge[1], parent);
                if(parentLeft == parentRight)
                    return -1;
                else
                {
                    countEdges++;
                    parent[parentRight] = parentLeft;
                    minMust = min(minMust, edge[2]);
                }
            }
            else
                optional.push_back({edge[2], edge[1], edge[0]});
        }
        sort(optional.begin(), optional.end(), greater<>());
        for(auto &[strength, left, right] : optional)
        {
            int parentLeft = find(left, parent), parentRight = find(right, parent);
            if(parentLeft != parentRight)
            {
                parent[parentRight] = parentLeft;
                countEdges++;
                if(countEdges == n - 1 - k)
                    minSingle = strength;
                minDouble = strength;
            }
        }
        return countEdges == n - 1 ? min({minMust, minSingle, minDouble * 2}) : -1;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenEdges = {{0, 1, 2, 1}, {1, 2, 3, 0}};
    int givenK = 1;
    int expectedAnswer = 2;
    assert(solution.maxStability(givenN, givenEdges, givenK) == expectedAnswer);

    givenN = 3;
    givenEdges = {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}};
    givenK = 2;
    expectedAnswer = 6;
    assert(solution.maxStability(givenN, givenEdges, givenK) == expectedAnswer);

    return 0;
}
