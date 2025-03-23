//#1976 Number of Ways to Arrive at Destination - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> directions(n);
        vector<pair<long long, int>> shortestPath(n);
        for(auto & path : shortestPath)
            path = {LLONG_MAX, 0};
        for(auto &road : roads)
        {
            directions[road[0]].push_back({road[1], road[2]});
            directions[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> path;
        path.emplace(0, 0);
        shortestPath[0] = {0, 1};
        while(!path.empty())
        {
            int stop = path.top().second;
            long long currTime = path.top().first;
            path.pop();
            for(auto &[neighbor, roadTime] : directions[stop])
            {
                if(currTime > shortestPath[stop].first)
                    continue;
                if(shortestPath[neighbor].first > shortestPath[stop].first + roadTime)
                {
                    shortestPath[neighbor].second = shortestPath[stop].second;
                    shortestPath[neighbor].first = shortestPath[stop].first + roadTime;
                    path.emplace(shortestPath[neighbor].first, neighbor);
                }
                else if(shortestPath[neighbor].first == shortestPath[stop].first + roadTime)
                {
                    shortestPath[neighbor].second = (shortestPath[neighbor].second + shortestPath[stop].second) % MOD;;
                }
            }
        }
        return shortestPath.back().second;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int given_n = 7;
    int expected_answer = 4;
    assert(solution.countPaths(given_n, given_roads) == expected_answer);

    given_roads = {{1, 0, 10}};
    given_n = 2;
    expected_answer = 1;
    assert(solution.countPaths(given_n, given_roads) == expected_answer);

    return 0;
}
