//#847 Shortest Path Visiting All Nodes - https://leetcode.com/problems/shortest-path-visiting-all-nodes/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = (int)graph.size(), result = 0;
        vector<vector<bool>> if_node_visited(N, vector<bool>(1 << N, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < N; i++)
        {
            q.push({i, (1 << i)});
        }
        while(!q.empty())
        {
            int size_q = (int)q.size();
            for(int i = 0; i < size_q; i++)
            {
                int cur_node = q.front().first, cur_path = q.front().second;
                q.pop();
                if(cur_path == (1 << N) - 1)
                    return result;
                if(if_node_visited[cur_node][cur_path])
                    continue;
                if_node_visited[cur_node][cur_path] = true;
                for(auto node : graph[cur_node])
                {
                    q.push({node, (1 << node) | cur_path});
                }
            }
            result++;
        }
        return result;

    }
};


int main()
{
    Solution solution;
    vector<vector<int>> given_graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    int  expected_answer = 4;
    assert(solution.shortestPathLength(given_graph) == expected_answer);

    given_graph = {{1, 2, 3}, {0}, {0}, {0}};
    expected_answer = 4;
    assert(solution.shortestPathLength(given_graph) == expected_answer);

    return 0;
}
