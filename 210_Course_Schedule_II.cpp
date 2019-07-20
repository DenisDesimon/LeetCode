//#210 Course Schedule II - https://leetcode.com/problems/course-schedule-ii/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> Indegree(numCourses, 0);
        vector<vector<int>> nodes_represent(numCourses);
        queue<int> nodes;
        vector<int> result;
        for(auto node : prerequisites)
        {
            nodes_represent[node[1]].push_back(node[0]);
            Indegree[node[0]]++;
        }
        for(int i = 0; i < (int)Indegree.size(); i++)
        {
            if(Indegree[i] == 0)
                nodes.push(i);
        }
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            result.push_back(cur_node);
            for(auto node : nodes_represent[cur_node])
            {
                if(--Indegree[node] == 0)
                    nodes.push(node);
            }

        }
        if((int)result.size() < numCourses)
            result.clear();
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nodes = {{1, 0}};
    int given_number = 2;
    vector<int> expected_answer = {0, 1};
    assert(solution.findOrder(given_number, given_nodes) == expected_answer);

    given_nodes = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    given_number = 4;
    expected_answer = {0, 1, 2, 3};
    assert(solution.findOrder(given_number, given_nodes) == expected_answer);

    return 0;
}
