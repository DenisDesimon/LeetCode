//#207 Course Schedule - https://leetcode.com/problems/course-schedule/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool is_cycle(int node, vector<vector<int>>& nodes, vector<bool>& visited, vector<bool>& checked){
        if(visited[node])
            return true;
        visited[node] = true;
        checked[node] = true;
        for(auto next_node : nodes[node])
        {
            if(is_cycle(next_node, nodes, visited, checked))
                return true;
        }
        visited[node] = false;
        return false;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> nodes(numCourses);
        vector<bool> visited(numCourses, false);
        vector<bool> checked(numCourses, false);
        for(auto node : prerequisites)
            nodes[node[0]].push_back(node[1]);
        for(int i = 0; i < numCourses; i++)
        {
            if(nodes[i].empty())
                continue;
            if(!checked[i] && is_cycle(i, nodes, visited, checked))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nodes = {{1, 0}};
    int given_number = 2;
    bool expected_answer = true;
    assert(solution.canFinish(given_number, given_nodes) == expected_answer);

    given_nodes = {{1, 0}, {0, 1}};
    given_number = 2;
    expected_answer = false;
    assert(solution.canFinish(given_number, given_nodes) == expected_answer);

    return 0;
}
