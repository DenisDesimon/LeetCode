//#797 All Paths From Source to Target - https://leetcode.com/problems/all-paths-from-source-to-target/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> nodes;
        vector<vector<int>> result;
        nodes.push({0, {0}});
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            for(auto node : graph[cur_node.first])
            {
                if(node == (int)graph.size() - 1)
                {
                    cur_node.second.push_back(graph.size() - 1);
                    result.push_back(cur_node.second);
                    cur_node.second.pop_back();
                }
                else
                {
                    cur_node.second.push_back(node);
                    nodes.push({node, cur_node.second});
                    cur_node.second.pop_back();
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> expected_answer = {{0, 1, 3}, {0, 2, 3}};
    assert(solution.allPathsSourceTarget(given_graph) == expected_answer);

    given_graph = {{1, 2}, {3}, {3}, {4}, {}};
    expected_answer = {{0, 1, 3, 4}, {0, 2, 3, 4}};
    assert(solution.allPathsSourceTarget(given_graph) == expected_answer);

    return 0;
}
