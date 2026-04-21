//#1722 Minimize Hamming Distance After Swap Operations - https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int result = 0;
        int n = source.size();
        vector<vector<int>> connections(n);
        for(auto &swap : allowedSwaps)
        {
            connections[swap[0]].push_back(swap[1]);
            connections[swap[1]].push_back(swap[0]);
        }
        vector<bool> visited(n);
        stack<int> nodes;
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            if(connections[i].empty())
            {
                if(source[i] != target[i])
                    result++;
            }
            else
            {
                nodes.push(i);
                unordered_map<int, int> countNums;
                while(!nodes.empty())
                {
                    int cur = nodes.top();
                    nodes.pop();
                    if(visited[cur])
                        continue;
                    countNums[source[cur]]++;
                    countNums[target[cur]]--;
                    visited[cur] = true;
                    for(auto &next : connections[cur])
                    {
                        if(!visited[next])
                            nodes.push(next);
                    }
                }
                int sum = 0;
                for(auto &count : countNums)
                {
                    sum += abs(count.second);
                }
                result += sum / 2;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenSource = {1, 2, 3, 4};
    vector<int> givenTarget = {2, 1, 4, 5};
    vector<vector<int>> givenSwaps = {{0,1}, {2, 3}};
    int expectedAnswer = 1;
    assert(solution.minimumHammingDistance(givenSource, givenTarget, givenSwaps) == expectedAnswer);

    givenSource = {5, 1, 2, 4, 3};
    givenTarget = {1, 5, 4, 2, 3};
    givenSwaps = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
    expectedAnswer = 0;
    assert(solution.minimumHammingDistance(givenSource, givenTarget, givenSwaps) == expectedAnswer);

    return 0;
}
