//#1971 Find if Path Exists in Graph - https://leetcode.com/problems/find-if-path-exists-in-graph/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> directions;
        for(auto &edge : edges)
        {
            directions[edge[0]].push_back(edge[1]);
            directions[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        stack<int> path;
        path.push(source);
        int stop;
        while(!path.empty()){
            stop = path.top();
            path.pop();
            if(stop == destination)
                return true;
            if(visited.count(stop))
                continue;
            visited.insert(stop);
            for(auto &direction : directions[stop])
            {
                if(visited.count(direction))
                    continue;
                path.push(direction);
            }

        }
        return false;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    vector<vector<int>> given_edges = {{0, 1}, {1, 2}, {2, 0}};
    int given_source = 0;
    int given_destination = 2;
    bool expected_answer = true;
    assert(solution.validPath(given_n, given_edges, given_source, given_destination) == expected_answer);

    given_n = 6;
    given_edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    given_source = 0;
    given_destination = 5;
    expected_answer = false;
    assert(solution.validPath(given_n, given_edges, given_source, given_destination) == expected_answer);

    return 0;
}
