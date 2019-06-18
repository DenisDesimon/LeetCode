//#785 Is Graph Bipartite? - https://leetcode.com/problems/is-graph-bipartite/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

class Solution {
    bool dfs(int s, vector<vector<int>>& graph, vector<int>& color, vector<bool>& visited)
    {
        if(visited[s])
            return true;
        visited[s] = true;
        for (auto node : graph[s]) {
            if(color[node] == 0)
                color[node] = (color[s] == 1 ? 2 : 1);
            else if(color[node] == color[s])
                return false;
            if(!dfs(node, graph, color, visited))
                return false;

        }
        return true;
    }
public:
    bool isBipartiteRecursion(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        vector<bool> visited(graph.size(), 0);
        color[0] = 1;
        for(int i = 0; i < (int)graph.size(); i++)
        {
        if(!dfs(i, graph, color, visited))
            return false;
        }
        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> if_visited(graph.size(), false);
        vector<int> color(graph.size(), 0);
        queue<int> nodes;
        for(int i = 0; i < (int)graph.size(); i++)
        {
            nodes.push(i);
            while(!nodes.empty())
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(if_visited[cur_node])
                    continue;
                if_visited[cur_node] = true;
                for(auto next_node : graph[cur_node])
                {
                    if(color[next_node] == 0)
                        color[next_node] = (color[cur_node] == 1 ? 2 : 1);
                    else if(color[next_node] == color[cur_node])
                            return false;
                    nodes.push(next_node);
                }

            }
        }
        return true;


    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_graph = {{3}, {2, 4}, {1}, {0, 4}, {1, 3}};
    bool  expected_answer = true;
    assert(solution.isBipartite(given_graph) == expected_answer);

    given_graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    expected_answer = false;
    assert(solution.isBipartite(given_graph) == expected_answer);

    return 0;
}

