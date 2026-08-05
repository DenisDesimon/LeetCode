//#3310 Remove Methods From Project - https://leetcode.com/problems/remove-methods-from-project/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> edgesCount(n);
        for(auto &invoke : invocations)
        {
            edges[invoke[0]].push_back(invoke[1]);
            edgesCount[invoke[1]]++;
        }
        stack<int> nodes;
        nodes.push(k);
        vector<int> result;
        vector<bool> isCorrupted(n);
        isCorrupted[k] = true;
        while(!nodes.empty())
        {
            int cur = nodes.top();
            nodes.pop();
            for(auto &next : edges[cur])
            {
                edgesCount[next]--;
                if(isCorrupted[next])
                    continue;
                nodes.push(next);
                isCorrupted[next] = true;
            }
        }
        bool canRemove = true;
        for(int i = 0; i < n; i++)
        {
            if(isCorrupted[i] && edgesCount[i] != 0)
            {
                canRemove = false;
                break;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(isCorrupted[i] && canRemove)
                continue;
            result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenInvocations = {{1, 2}, {0, 1}, {3, 2}};
    int givenN = 4;
    int givenK = 1;
    vector<int> expectedAnswer = {0, 1, 2, 3};
    assert(solution.remainingMethods(givenN, givenK, givenInvocations) == expectedAnswer);

    givenInvocations = {{1, 2}, {0, 1}, {3, 2}};
    givenN = 4;
    givenK = 1;
    expectedAnswer = {0, 1, 2, 3};
    assert(solution.remainingMethods(givenN, givenK, givenInvocations) == expectedAnswer);

    return 0;
}
