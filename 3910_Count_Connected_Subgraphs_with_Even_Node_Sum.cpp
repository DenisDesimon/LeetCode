//#3910 Count Connected Subgraphs with Even Node Sum - https://leetcode.com/problems/count-connected-subgraphs-with-even-node-sum/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> connections(n);
        int result = 0;
        for(auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        int total = 1 << n;
        for(int i = 1; i < total; i++)
        {
            stack<int> nodes;
            int idx = 0;
            int mask = i;
            while(!(i & (1 << idx)))
                idx++;
            nodes.push(idx);
            int sum = 0;
            while(!nodes.empty())
            {
                int cur = nodes.top();
                nodes.pop();
                if(!(mask & (1 << cur)))
                    continue;
                mask ^= (1 << cur);
                sum += nums[cur];
                if(mask == 0)
                {
                    if(sum % 2 == 0)
                        result++;
                    break;
                }
                for(auto &next : connections[cur])
                {
                    if(mask & (1 << next))
                        nodes.push(next);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 0, 1};
    vector<vector<int>> givenEdges = {{0, 1}, {1, 2}};
    int expectedAnswer = 2;
    assert(solution.evenSumSubgraphs(givenNums, givenEdges) == expectedAnswer);

    givenNums = {1};
    givenEdges = {};
    expectedAnswer = 0;
    assert(solution.evenSumSubgraphs(givenNums, givenEdges) == expectedAnswer);

    return 0;
}
