//#2092 Find All People With Secret - https://leetcode.com/problems/find-all-people-with-secret/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &meeting : meetings)
        {
            graph[meeting[0]].push_back({meeting[2], meeting[1]});
            graph[meeting[1]].push_back({meeting[2], meeting[0]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes;
        vector<bool> isKeeper(n);
        vector<int> result;
        nodes.push({0, 0});
        nodes.push({0, firstPerson});
        while(!nodes.empty())
        {
            pair<int, int> cur = nodes.top();
            nodes.pop();
            if(isKeeper[cur.second])
                continue;
            isKeeper[cur.second] = true;
            for(auto &[time, next] : graph[cur.second])
            {
                if(!isKeeper[next] && time >= cur.first)
                    nodes.push({time, next});
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(isKeeper[i])
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 6;
    vector<vector<int>> givenMeetings  = {{1, 2, 5}, {2, 3, 8}, {1, 5, 10}};
    int givenFirstPerson = 1;
    vector<int> expectedAnswer = {0, 1, 2, 3, 5};
    assert(solution.findAllPeople(givenN, givenMeetings, givenFirstPerson) == expectedAnswer);

    givenN = 5;
    givenMeetings = {{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    givenFirstPerson = 1;
    expectedAnswer = {0, 1, 2, 3, 4};
    assert(solution.findAllPeople(givenN, givenMeetings, givenFirstPerson) == expectedAnswer);

    return 0;
}
