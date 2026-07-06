//#3975 Filter Occupied Intervals - https://leetcode.com/problems/filter-occupied-intervals/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end(), [] (vector<int> &a, vector<int> &b){return a[0] < b[0];});
        vector<vector<int>> result;
        for(auto &cur : occupiedIntervals)
        {
            if(result.empty())
                result.push_back(cur);
            else
            {
                if(cur[0] <= result.back()[1] + 1)
                {
                    result.back()[1] = max(result.back()[1], cur[1]);
                }
                else
                    result.push_back(cur);
            }
        }
        for(int i = 0; i < (int)result.size(); i++)
        {
            if(result[i][0] < freeStart && result[i][1] >= freeStart)
            {
                if(result[i][1] > freeEnd)
                {
                    result.insert(result.begin() + i + 1, {freeEnd + 1, result[i][1]});
                    result[i][1] = freeStart - 1;
                    break;
                }
                else
                    result[i][1] = freeStart - 1;
            }
            else if(result[i][0] >= freeStart && result[i][1] <= freeEnd)
            {
                result.erase(result.begin() + i);
                i--;
            }
            else if(result[i][0] <= freeEnd && result[i][1] > freeEnd)
            {
                result[i][0] = freeEnd + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenIntervals = {{2, 6}, {4, 8}, {10, 10}, {10, 12}, {14, 16}};
    int givenStart = 7;
    int givenEnd = 11;
    vector<vector<int>> expectedAnswer = {{2, 6}, {12, 12}, {14, 16}};
    assert(solution.filterOccupiedIntervals(givenIntervals, givenStart, givenEnd) == expectedAnswer);

    givenIntervals = {{1, 5}, {2, 3}};
    givenStart = 3;
    givenEnd = 8;
    expectedAnswer = {{1, 2}};
    assert(solution.filterOccupiedIntervals(givenIntervals, givenStart, givenEnd) == expectedAnswer);

    return 0;
}
