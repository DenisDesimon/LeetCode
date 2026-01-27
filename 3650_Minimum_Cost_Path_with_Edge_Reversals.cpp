//#3650 Minimum Cost Path with Edge Reversals - https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> edgeWeight(n);
        for(auto &edge : edges)
        {
            edgeWeight[edge[0]].push_back({edge[1], edge[2]});
            edgeWeight[edge[1]].push_back({edge[0], 2 * edge[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distanceEdge;
        for(auto &edge : edgeWeight[0])
        {
            distanceEdge.push({edge.second, edge.first});
        }
        vector<bool> visited(n);
        while(!distanceEdge.empty())
        {
            int curEdge = distanceEdge.top().second;
            int curPath = distanceEdge.top().first;
            distanceEdge.pop();
            if(visited[curEdge])
                continue;
            visited[curEdge] = true;
            if(curEdge == n - 1)
                return curPath;
            for(auto &edge : edgeWeight[curEdge])
            {
                distanceEdge.push({curPath + edge.second, edge.first});
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenEdges  = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    int givenN = 4;
    int expectedAnswer = 5;
    assert(solution.minCost(givenN, givenEdges) == expectedAnswer);

    givenEdges  = {{0, 2, 1}, {2, 1, 1}, {1, 3, 1}, {2, 3, 3}};
    givenN = 4;
    expectedAnswer = 3;
    assert(solution.minCost(givenN, givenEdges) == expectedAnswer);

    return 0;
}
