//#802 Find Eventual Safe States - https://leetcode.com/problems/find-eventual-safe-states/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    bool is_cycle(int& node, vector<vector<int>>& nodes, vector<bool>& visited, vector<bool>& checked, vector<int>& result){
        if(visited[node])
            return true;
        visited[node] = true;
        for(auto &next_node : nodes[node])
        {
            if(!checked[next_node] && is_cycle(next_node, nodes, visited, checked, result))
                return true;
        }
        visited[node] = false;
        checked[node] = true;
        result.push_back(node);
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<bool> checked(graph.size(), false);
        vector<int> result;
        for(int i = 0; i < (int)graph.size(); i++)
        {
            if(!checked[i])
                is_cycle(i, graph, visited, checked, result);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> expected_answer = {2, 4, 5, 6};
    assert(solution.eventualSafeNodes(given_graph) == expected_answer);

    return 0;
}
