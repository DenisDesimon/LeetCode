//#1200 Minimum Absolute Difference - https://leetcode.com/problems/minimum-absolute-difference/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        for(int i = 1; i < (int)arr.size(); i++)
        {
            int dif = arr[i] - arr[i - 1];
            if(dif < minDif)
            {
                minDif = dif;
                result.clear();
                result.push_back({arr[i - 1], arr[i]});
            }
            else if(dif == minDif)
                result.push_back({arr[i - 1], arr[i]});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr  = {4, 2, 1, 3};
    vector<vector<int>> expectedAnswer = {{1, 2}, {2, 3}, {3, 4}};
    assert(solution.minimumAbsDifference(givenArr) == expectedAnswer);

    givenArr  = {1, 3, 6, 10, 15};
    expectedAnswer = {{1, 3}};
    assert(solution.minimumAbsDifference(givenArr) == expectedAnswer);

    return 0;
}
