//#1029 Two City Scheduling - https://leetcode.com/problems/two-city-scheduling/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int result = 0;
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){return a[0] - a[1] < b[0] - b[1];});
        for(int i = 0; i < (int)costs.size(); i++)
        {
            if(i < (int)costs.size() / 2)
                result += costs[i][0];
            else
                result += costs[i][1];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    int expected_answer = 110;
    assert(solution.twoCitySchedCost(given_costs) == expected_answer);

    given_costs = {{50, 150}, {200, 70}, {300, 100}, {60, 250}};
    expected_answer = 280;
    assert(solution.twoCitySchedCost(given_costs) == expected_answer);

    return 0;
}
