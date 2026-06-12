//#3559 Number of Ways to Assign Edge Weights II - https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;

int mod = 1e9 + 7;
const int N = 1e5 + 2;
int powers[N];
auto init = []{
    powers[0] = 1;
    for(int i = 1; i < N; i++)
    {
        powers[i] = powers[i - 1] * 2 % mod;
    }
    return 0;
}();



class LCA{
    int n;
    int m;
    vector<int> dist;
    vector<vector<int>> connections;
    vector<vector<int>> parent;
public:
    LCA(vector<vector<int>> edges){
        n = edges.size() + 1;
        m = (log(n) / log(2)) + 1;
        dist.resize(n + 1);
        connections.resize(n + 1);
        parent.resize(n + 1, vector<int>(m, 0));
        for(auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        dfs(1, 0);
        for(int step = 1; step < m; step++)
        {
            for(int node = 1; node <= n; node++)
            {
                parent[node][step] = parent[parent[node][step - 1]][step - 1];
            }
        }
    }
    void dfs(int cur, int prev){
        parent[cur][0] = prev;
        for(auto &next : connections[cur])
        {
            if(next == prev)
                continue;
            dist[next] = dist[cur] + 1;
            dfs(next, cur);
        }
    }

    int lca(int u, int v){
        if(dist[u] > dist[v])
            swap(u, v);
        for(int i = m - 1; i >= 0; i--)
        {
            if(dist[u] <= dist[parent[v][i]])
                v = parent[v][i];
        }
        if(u == v)
            return u;
        for(int i = m - 1; i >= 0; i--)
        {
            if(parent[u][i] != parent[v][i])
            {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }
    int getDistance(int u, int v){
        return dist[u] + dist[v] - 2 * dist[lca(u, v)];
    }
};

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LCA lca(edges);
        vector<int> result;
        for(auto &query : queries)
        {
            if(query[0] != query[1])
                result.push_back(powers[lca.getDistance(query[0], query[1]) - 1]);
            else
                result.push_back(0);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenEdges = {{1, 2}};
    vector<vector<int>> givenQueries = {{1, 1}, {1, 2}};
    vector<int> expectedAnswer = {0, 1};
    assert(solution.assignEdgeWeights(givenEdges, givenQueries) == expectedAnswer);

    givenEdges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};
    givenQueries = {{1, 4}, {3, 4}, {2, 5}};
    expectedAnswer = {2, 1, 4};
    assert(solution.assignEdgeWeights(givenEdges, givenQueries) == expectedAnswer);

    return 0;
}
