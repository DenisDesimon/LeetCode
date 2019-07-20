//#743 Network Delay Time - https://leetcode.com/problems/network-delay-time/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pair<int, int>> nodes;
        vector<vector<pair<int, int>>> adj(N + 1);
        vector<int> distance(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        int result = 0;
        for(auto time : times)
        {
            adj[time[0]].push_back({time[1], time[2]});
        }
        nodes.push({0, K});
        distance[K] = 0;
        while(!nodes.empty())
        {
            auto cur_node = nodes.top().second;
            nodes.pop();
            if(visited[cur_node])
                continue;
            visited[cur_node] = true;
            for(auto node : adj[cur_node])
            {
                if(distance[cur_node] + node.second < distance[node.first])
                {
                    distance[node.first] = distance[cur_node] + node.second;
                    nodes.push({-distance[node.first], node.first});
                }
            }
        }
        for(int i = 1; i < N + 1; i++)
        {
            if(distance[i] == INT_MAX)
                return -1;
            result = max(result, distance[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int given_N = 4;
    int given_K = 2;
    int expected_answer = 2;
    assert(solution.networkDelayTime(given_times, given_N, given_K) == expected_answer);

    given_times = {{1, 2, 1}, {2, 1, 3}};
    given_N = 2;
    given_K = 2;
    expected_answer = 3;
    assert(solution.networkDelayTime(given_times, given_N, given_K) == expected_answer);

    return 0;
}
