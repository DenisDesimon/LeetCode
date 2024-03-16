//#3067 Count Pairs of Connectable Servers in a Weighted Tree Network - https://leetcode.com/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int findPairs(vector<vector<pair<int, int>>> &graph, int current, int previous, int distance, int signalSpeed){
        int count = distance % signalSpeed ? 0 : 1;
        for(auto &[next, dist] : graph[current])
        {
            if(next != previous)
                count += findPairs(graph, next, current, distance + dist, signalSpeed);
        }
        return count;

    }
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        vector<vector<pair<int, int>>> graph(edges.size() + 1);
        vector<int> result;
        for(auto &edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        for(int i = 0; i < (int)graph.size(); i++)
        {
            int branch = 0;
            int sumPairs = 0;
            for(auto &[next, dist] : graph[i])
            {
                int count = findPairs(graph, next, i, dist, signalSpeed);
                sumPairs += count * branch;
                branch += count;
            }
            result.push_back(sumPairs);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_edges = {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
    int given_signalSpeed = 1;
    vector<int> expected_answer = {0, 4, 6, 6, 4, 0};
    assert(solution.countPairsOfConnectableServers(given_edges, given_signalSpeed) == expected_answer);

    given_edges = {{0, 6, 3}, {6, 5, 3}, {0, 3, 1}, {3, 2, 7}, {3, 1, 6}, {3, 4, 2}};
    given_signalSpeed = 3;
    expected_answer = {2, 0, 0, 0, 0, 0, 2};
    assert(solution.countPairsOfConnectableServers(given_edges, given_signalSpeed) == expected_answer);

    return 0;
}
