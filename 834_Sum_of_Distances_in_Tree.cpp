//#834 Sum of Distances in Tree - https://leetcode.com/problems/sum-of-distances-in-tree/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void find_first_result(int cur_node, int parent, vector<int>& result, vector<int>& count_nodes, vector<vector<int>>& nodes){
            for(auto node : nodes[cur_node])
            {
                if(node != parent)
                {
                    find_first_result(node, cur_node, result, count_nodes, nodes);
                    count_nodes[cur_node] += count_nodes[node];
                    result[cur_node] += result[node] + count_nodes[node];
                }
            }

    }
    void find_rest_result(int cur_node, int parent, vector<int>& result, vector<int>& count_nodes, vector<vector<int>>& nodes, int N){
        for(auto node : nodes[cur_node])
        {
            if(node != parent)
            {
                result[node] = result[cur_node] - count_nodes[node] + (N - count_nodes[node]);
                find_rest_result(node, cur_node, result, count_nodes, nodes, N);
            }
        }

    }

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> nodes(N);
        vector<int> result(N, 0);
        vector<int> count_nodes(N, 1);
        for(auto edge : edges)
        {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        find_first_result(0, -1, result, count_nodes, nodes);
        find_rest_result(0, -1, result, count_nodes, nodes, N);
        return result;

    }
};



int main()
{
    Solution solution;
    vector<vector<int>> given_nodes = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> expected_answer = {8, 12, 6, 10, 10, 10};
    int given_N = 6;
    assert(solution.sumOfDistancesInTree(given_N, given_nodes) == expected_answer);

    return 0;
}
