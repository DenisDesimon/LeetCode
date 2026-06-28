//#1846 Maximum Element After Decreasing and Rearranging - https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr.front() = 1;
        for(int i = 1; i < (int)arr.size(); i++)
        {
            if(arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 2, 1, 2, 1};
    int expectedAnswer = 2;
    assert(solution.maximumElementAfterDecrementingAndRearranging(givenNums) == expectedAnswer);

    givenNums = {73, 98, 9};
    expectedAnswer = 3;
    assert(solution.maximumElementAfterDecrementingAndRearranging(givenNums) == expectedAnswer);

    return 0;
}
