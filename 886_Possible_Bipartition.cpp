//#886 Possible Bipartition - https://leetcode.com/problems/possible-bipartition/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
    vector<vector<int>> nodes;
    unordered_map<int, int> colors;
    bool dfs(int cur_node, int color){
        if(colors.count(cur_node))
            return colors[cur_node] == color;
        colors[cur_node] = color;
        for(auto& node : nodes[cur_node])
        {
            if(!dfs(node, color ^ 1))
                return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes){
        colors.clear();
        nodes.resize(N);
        for(auto& dislike : dislikes)
        {
            nodes[dislike[0] - 1].push_back(dislike[1] - 1);
            nodes[dislike[1] - 1].push_back(dislike[0] - 1);
        }
        for(int i = 0; i < N; i++)
        {
            if(!colors.count(i) && !dfs(i, 0))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int given_N = 4;
    vector<vector<int>> given_dislikes = {{1, 2}, {1, 3}, {2, 4}};
    bool expected_answer = true;
    assert(solution.possibleBipartition(given_N, given_dislikes) == expected_answer);

    given_N = 3;
    given_dislikes = {{1, 2}, {1, 3}, {2, 3}};
    expected_answer = false;
    assert(solution.possibleBipartition(given_N, given_dislikes) == expected_answer);

    return 0;
}
