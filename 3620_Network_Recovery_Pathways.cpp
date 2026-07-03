//#3620 Network Recovery Pathways - https://leetcode.com/problems/network-recovery-pathways/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> connections(n);
        int low = INT_MAX, high = INT_MIN;
        for(auto &edge : edges)
        {
            if(!online[edge[0]] || !online[edge[1]])
                continue;
            connections[edge[0]].push_back({edge[1], edge[2]});
            low = min(low, edge[2]);
            high = max(high, edge[2]);
        }
        auto isValid = [&](int val){
            vector<bool> visited(n);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> nodes;
            nodes.push({0, 0});
            while(!nodes.empty())
            {
                int curNode = nodes.top().second;
                long long totalW = nodes.top().first;
                nodes.pop();
                if(visited[curNode])
                    continue;
                if(totalW > k)
                    return false;
                if(curNode == n - 1)
                    return true;
                visited[curNode] = true;
                for(auto &next : connections[curNode])
                {
                    if(next.second < val || visited[next.first])
                        continue;
                    nodes.push({totalW + next.second, next.first});
                }
            }
            return false;
        };
        if(!isValid(low))
            return -1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(isValid(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenEdges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> givenOnline = {true, true, true, true};
    int givenK = 10;
    int expectedAnswer = 3;
    assert(solution.findMaxPathScore(givenEdges, givenOnline, givenK) == expectedAnswer);

    givenEdges = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3 ,4, 2}, {2 ,4, 6}};
    givenOnline = {true, true, true, false, true};
    givenK = 12;
    expectedAnswer = 6;
    assert(solution.findMaxPathScore(givenEdges, givenOnline, givenK) == expectedAnswer);

    return 0;
}
