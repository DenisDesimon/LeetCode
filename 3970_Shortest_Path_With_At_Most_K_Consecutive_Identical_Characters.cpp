//#3970 Shortest Path With At Most K Consecutive Identical Characters - https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;


class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> connections(n);
        for(auto &edge : edges)
        {
            connections[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> nodes;
        vector<vector<bool>> visited(n, vector<bool>(k + 1));
        nodes.push({0, 0, 1});
        while(!nodes.empty())
        {
            auto [weight, node, count] = nodes.top();
            nodes.pop();
            if(node == n - 1)
                return weight;
            if(visited[node][count])
                continue;
            visited[node][count] = true;
            for(auto &next : connections[node])
            {
                int nextCount = labels[node] == labels[next.first] ? count + 1 : 1;
                if(nextCount > k)
                    continue;
                if(!visited[next.first][nextCount])
                    nodes.push({weight + next.second, next.first, nextCount});
            }
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenEdges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 3}};
    string givenLabels = "aab";
    int givenK = 1;
    int expectedAnswer = 3;
    assert(solution.shortestPath(givenN, givenEdges, givenLabels, givenK) == expectedAnswer);

    givenN = 3;
    givenEdges = {{0, 1, 1}, {1 ,2, 1}, {0, 2, 3}};
    givenLabels = "aab";
    givenK = 2;
    expectedAnswer = 2;
    assert(solution.shortestPath(givenN, givenEdges, givenLabels, givenK) == expectedAnswer);

    return 0;
}
