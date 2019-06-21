//#310 Minimum Height Trees - https://leetcode.com/problems/minimum-height-trees/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result;
        if(edges.size() == 0)
        {
            result.push_back(0);
            return result;
        }
        unordered_map<int, vector<int>> nodes;
        queue<int> leaves;
        for(auto edge : edges)
        {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < (int)nodes.size(); i++)
        {
            if(nodes[i].size() == 1)
                leaves.push(i);
        }
        while(n > 2)
        {
            int leave_size = leaves.size();
            while(leave_size--)
            {
                int cur_node = leaves.front();
                leaves.pop();
                int parent_node = nodes[cur_node][0];
                nodes[parent_node].erase(find(nodes[parent_node].begin(), nodes[parent_node].end(), cur_node));
                if(nodes[parent_node].size() == 1)
                    leaves.push(parent_node);
                nodes.erase(cur_node);
                n--;
            }
        }
        for(auto node : nodes)
        {
            result.push_back(node.first);
        }
        return result;

    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int>  expected_answer = {1};
    assert(solution.findMinHeightTrees(4, given_edges) == expected_answer);

    given_edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    expected_answer = {4, 3};
    assert(solution.findMinHeightTrees(6, given_edges) == expected_answer);

    return 0;
}
