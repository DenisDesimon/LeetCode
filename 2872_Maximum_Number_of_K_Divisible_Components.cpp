//#2872 Maximum Number of K-Divisible Components - https://leetcode.com/problems/maximum-number-of-k-divisible-components/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>> &treeEdges, int cur, int parent, int &result, vector<int> &values, int &k){
        int sum = 0;
        for(auto &edge : treeEdges[cur])
        {
            if(edge == parent)
                continue;
            sum += dfs(treeEdges, edge, cur, result, values, k);
            sum %= k;
        }
        sum += values[cur];
        if(sum % k == 0)
            result++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> treeEdges(n);
        for(auto &edge : edges)
        {
            treeEdges[edge[0]].push_back(edge[1]);
            treeEdges[edge[1]].push_back(edge[0]);
        }
        int result = 0;
        dfs(treeEdges, 0, -1, result, values, k);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenEdges = {{0, 2}, {1, 2}, {1, 3}, {2, 4}};
    vector<int> givenValues = {1, 8, 1, 4, 4};
    int givenN = 5;
    int givenK = 6;
    int expectedAnswer = 2;
    assert(solution.maxKDivisibleComponents(givenN, givenEdges, givenValues, givenK) == expectedAnswer);

    givenEdges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    givenValues = {3, 0, 6, 1, 5, 2, 1};
    givenN = 7;
    givenK = 3;
    expectedAnswer = 3;
    assert(solution.maxKDivisibleComponents(givenN, givenEdges, givenValues, givenK) == expectedAnswer);

    return 0;
}
