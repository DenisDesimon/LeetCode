//#3607 Power Grid Maintenance - https://leetcode.com/problems/power-grid-maintenance/
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

class Solution {
private:
    void dfs(int curNode, vector<vector<int>> &edges, vector<set<int>> &connectedStations,
             vector<bool> &visited, vector<int> &powerId, int id){
        visited[curNode] = true;
        powerId[curNode] = id;
        connectedStations[id].insert(curNode);
        for(auto &edge : edges[curNode])
        {
            if(!visited[edge])
                dfs(edge, edges, connectedStations, visited, powerId, id);
        }

    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> edges(c + 1);
        vector<set<int>> connectedStations(c + 1);
        vector<int> powerId(c + 1);
        vector<bool> visited(c + 1);
        for(auto &connection : connections)
        {
            edges[connection[0]].push_back(connection[1]);
            edges[connection[1]].push_back(connection[0]);
        }
        for(int i = 1; i <= c; i++)
        {
            if(!visited[i])
                dfs(i, edges, connectedStations, visited, powerId, i);
        }
        vector<int> results;
        for(auto &query : queries)
        {
            if(query[0] == 1)
            {
                auto id = powerId[query[1]];
                if(connectedStations[id].count(query[1]))
                    results.push_back(query[1]);
                else if(!connectedStations[id].empty())
                    results.push_back(*(connectedStations[id].begin()));
                else
                    results.push_back(-1);
            }
            else
            {
                auto id = powerId[query[1]];
                if(connectedStations[id].count(query[1]))
                    connectedStations[id].erase(query[1]);
            }
        }
        return results;
    }
};

int main()
{
    Solution solution;
    int givenC = 5;
    vector<vector<int>> givenConnections = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    vector<vector<int>> givenQueries = {{1, 3}, {2 ,1}, {1, 1} ,{2, 2}, {1, 2}};
    vector<int> expectedAnswer = {3, 2, 3};
    assert(solution.processQueries(givenC, givenConnections, givenQueries) == expectedAnswer);

    givenC = 3;
    givenConnections = {};
    givenQueries = {{1, 1}, {2, 1}, {1, 1}};
    expectedAnswer = {1, -1};
    assert(solution.processQueries(givenC, givenConnections, givenQueries) == expectedAnswer);

    return 0;
}
