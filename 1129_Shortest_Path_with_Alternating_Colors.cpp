//#1129 Shortest Path with Alternating Colors - https://leetcode.com/problems/shortest-path-with-alternating-colors/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        queue<pair<int, int>> nodes;
        vector<vector<int>> red_nodes(n);
        vector<vector<int>> blue_nodes(n);
        map<pair<int, int>, int> visited;
        vector<int> result;
        for(auto &red_node : red_edges)
        {
            red_nodes[red_node[0]].push_back(red_node[1]);
        }
        for(auto &blue_node : blue_edges)
        {
            blue_nodes[blue_node[0]].push_back(blue_node[1]);
        }
        for(int i = 0; i < n; i++)
        {
            nodes.push({0, 0});
            nodes.push({0, 1});
            int path = 0;
            visited.clear();
            while(!nodes.empty())
            {
                int size_nodes = (int)nodes.size();
                while(size_nodes--)
                {
                    auto cur_node = nodes.front();
                    nodes.pop();
                    if(visited[cur_node])
                        continue;
                    if(cur_node.first == i)
                    {
                        while(!nodes.empty())
                            nodes.pop();
                        result.push_back(path);
                        break;
                    }
                    visited[cur_node] = 1;
                    if(cur_node.second == 0)
                    {
                        for(auto &node : blue_nodes[cur_node.first])
                        {
                            nodes.push({node, 1});
                        }
                    }
                    else if(cur_node.second == 1)
                    {
                        for(auto &node : red_nodes[cur_node.first])
                        {
                            nodes.push({node, 0});
                        }
                    }
                }
                path++;
            }
            if((int)result.size() < i + 1)
                result.push_back(-1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> result;
    vector<vector<int>> red_edges = {{0, 1}, {1, 2}};
    vector<vector<int>> blue_edges = {};
    int given_n = 3;
    vector<int> expected_answer = {0, 1, -1};
    assert(solution.shortestAlternatingPaths(given_n, red_edges, blue_edges) == expected_answer);

    red_edges = {{0, 1}, {0, 2}};
    blue_edges = {{1, 0}};
    given_n = 3;
    expected_answer = {0, 1, 1};
    assert(solution.shortestAlternatingPaths(given_n, red_edges, blue_edges) == expected_answer);

    return 0;
}
