//#3531 Count Covered Buildings - https://leetcode.com/problems/count-covered-buildings/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<pair<int, int>> buildingX(n + 1, {n, 0}), buildingY(n + 1, {n, 0});
        int result = 0;
        for(auto &building : buildings)
        {
            buildingX[building[0]].first = min(building[1], buildingX[building[0]].first);
            buildingX[building[0]].second = max(building[1], buildingX[building[0]].second);
            buildingY[building[1]].first = min(building[0], buildingY[building[1]].first);
            buildingY[building[1]].second = max(building[0], buildingY[building[1]].second);
        }
        for(auto &building : buildings)
        {
            if(buildingX[building[0]].first == building[1])
                continue;
            if(buildingX[building[0]].second == building[1])
                continue;
            if(buildingY[building[1]].first == building[0])
                continue;
            if(buildingY[building[1]].second == building[0])
                continue;
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenBuildings = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    int expectedAnswer = 0;
    assert(solution.countCoveredBuildings(givenN, givenBuildings) == expectedAnswer);

    givenN = 5;
    givenBuildings = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    expectedAnswer = 1;
    assert(solution.countCoveredBuildings(givenN, givenBuildings) == expectedAnswer);

    return 0;
}
