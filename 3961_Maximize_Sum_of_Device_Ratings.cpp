//#3961 Maximize Sum of Device Ratings - https://leetcode.com/problems/maximize-sum-of-device-ratings/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        long long result = 0;
        int secondMin = INT_MAX;
        int firstMin = INT_MAX;
        if(n == 1)
        {
            for(auto &capacity : units.front())
                firstMin = min(firstMin, capacity);
            return firstMin;
        }
        if(units.front().size() == 1)
        {
            for(auto &unit : units)
                result += unit.front();
            return result;
        }
        for(int i = 0; i < n; i++)
        {
            nth_element(units[i].begin(), units[i].begin() + 1, units[i].end());
            secondMin = min(secondMin, units[i][1]);
            result += units[i][1];
            firstMin = min(firstMin, units[i].front());
        }
        result -= secondMin;
        result += firstMin;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenUnits = {{1, 3}, {2, 2}};
    int expectedAnswer = 4;
    assert(solution.maxRatings(givenUnits) == expectedAnswer);

    givenUnits = {{1, 2, 3}, {4, 5, 6}};
    expectedAnswer = 6;
    assert(solution.maxRatings(givenUnits) == expectedAnswer);

    return 0;
}
