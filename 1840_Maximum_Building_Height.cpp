//#1840 Maximum Building Height - https://leetcode.com/problems/maximum-building-height/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        if(restrictions.back()[0] != n)
            restrictions.push_back({n, n - 1});
        int m = restrictions.size();

        for(int i = 1; i < m; i++)
        {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]));
        }

        for(int i = m - 2; i >= 0; i--)
        {
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]));
        }

        int result = 0;

        for(int i = 0; i < m - 1; i++)
        {
            int curMax = ((restrictions[i + 1][0] - restrictions[i][0]) + restrictions[i][1] + restrictions[i + 1][1]) / 2;
            result = max(result, curMax);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 5;
    vector<vector<int>> givenRestrictions = {{2, 1}, {4, 1}};
    int expectedAnswer = 2;
    assert(solution.maxBuilding(givenN, givenRestrictions) == expectedAnswer);

    givenN = 6;
    givenRestrictions = {};
    expectedAnswer = 5;
    assert(solution.maxBuilding(givenN, givenRestrictions) == expectedAnswer);

    return 0;
}
