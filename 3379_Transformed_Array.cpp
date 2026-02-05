//#3379 Transformed Array - https://leetcode.com/problems/transformed-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, -2, 1, 1};
    vector<int> expectedAnswer = {1, 1, 1, 3};
    assert(solution.constructTransformedArray(givenNums) == expectedAnswer);

    givenNums = {-1, 4, -1};
    expectedAnswer = {-1, -1, 4};
    assert(solution.constructTransformedArray(givenNums) == expectedAnswer);


    return 0;
}
