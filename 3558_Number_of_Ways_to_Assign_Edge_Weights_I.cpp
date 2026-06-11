//#3558 Number of Ways to Assign Edge Weights I - https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


class Solution {
private:
    int mod = 1e9 + 7;
    int fastPower(long long x, int pow){
        long long result = 1;
        while(pow)
        {
            if(pow & 1)
                result = (result * x) % mod;
            x = (x * x) % mod;
            pow >>= 1;
        }
        return result;
    }
    int dfs(int cur, int prev, vector<vector<int>> &connections){
        int result = 0;
        for(auto &next : connections[cur])
        {
            if(next == prev)
                continue;
            result = max(result, dfs(next, cur, connections) + 1);
        }
        return result;
    }
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> connections(n + 1);
        for(auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        int depth = dfs(1, 0, connections);
        return fastPower(2, depth - 1);
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenEdges = {{1, 2}};
    int expectedAnswer = 1;
    assert(solution.assignEdgeWeights(givenEdges) == expectedAnswer);

    givenEdges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    expectedAnswer = 2;
    assert(solution.assignEdgeWeights(givenEdges) == expectedAnswer);

    return 0;
}
