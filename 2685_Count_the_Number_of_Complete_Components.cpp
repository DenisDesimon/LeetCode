//#2685 Count the Number of Complete Components - https://leetcode.com/problems/count-the-number-of-complete-components/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <algorithm>
#include <cassert>
using namespace std;

/*
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> directions(n);
        int result = 0;
        unordered_set<int> visited;
        for(auto &edge : edges)
        {
            directions[edge[0]].push_back(edge[1]);
            directions[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(visited.count(i))
                continue;
            bool flag = true;
            stack<int> path;
            path.push(i);
            unordered_set<int> componentEdges;
            int count = directions[i].size();
            for(auto &edge : directions[i])
                componentEdges.insert(edge);
            componentEdges.insert(i);
            while(!path.empty())
            {
                int vertice = path.top();
                path.pop();
                if(visited.count(vertice))
                    continue;
                visited.insert(vertice);
                for(auto &edge : directions[vertice])
                {
                    if(!componentEdges.count(edge) || (int)directions[edge].size() != count)
                        flag = false;
                    if(visited.count(edge))
                        continue;
                    path.push(edge);
                }
            }
            if(flag)
                result++;

        }
        return result;
    }
};
*/

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> directions(n);
        unordered_map<string, int> directonsCount;
        int result = 0;
        for(int i = 0; i < n; i++)
            directions[i].push_back(i);
        for(auto &edge : edges)
        {
            directions[edge[0]].push_back(edge[1]);
            directions[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < n; i++)
        {
            sort(directions[i].begin(), directions[i].end());
            string neighbors;
            for(auto &neighbor : directions[i])
            {
                neighbors +=  to_string(neighbor) + ' ';
            }
            directonsCount[neighbors]++;
        }
        for(auto &component : directonsCount)
        {
            if(count(component.first.begin(), component.first.end(), ' ') == component.second)
                result++;
        }
        return result;
    }
};




int main()
{
    Solution solution;
    int given_n = 5;
    vector<vector<int>> given_edges = {{1, 0}, {3, 1}, {4, 2}, {4, 3}};
    int expected_answer = 0;
    assert(solution.countCompleteComponents(given_n, given_edges) == expected_answer);

    given_n = 6;
    given_edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    expected_answer = 3;
    assert(solution.countCompleteComponents(given_n, given_edges) == expected_answer);

    return 0;
}
