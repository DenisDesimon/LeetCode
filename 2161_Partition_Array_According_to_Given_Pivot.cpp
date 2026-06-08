//#2161 Partition Array According to Given Pivot - https://leetcode.com/problems/partition-array-according-to-given-pivot/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> low, mid, high;
        for(auto &num : nums)
        {
            if(num < pivot)
                low.push_back(num);
            else if(num > pivot)
                high.push_back(num);
            else
                mid.push_back(num);
        }
        vector<int> result;
        result.insert(result.end(), low.begin(), low.end());
        result.insert(result.end(), mid.begin(), mid.end());
        result.insert(result.end(), high.begin(), high.end());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {9, 12, 5, 10, 14, 3, 10};
    int givenPivot = 10;
    vector<int> expectedAnswer = {9, 5, 3, 10, 10, 12, 14};
    assert(solution.pivotArray(givenNums, givenPivot) == expectedAnswer);

    givenNums = {-3, 4, 3, 2};
    givenPivot = 2;
    expectedAnswer = {-3, 2, 4, 3};
    assert(solution.pivotArray(givenNums, givenPivot) == expectedAnswer);

    return 0;
}
