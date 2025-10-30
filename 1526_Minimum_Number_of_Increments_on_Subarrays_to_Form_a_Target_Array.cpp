//#1526 Minimum Number of Increments on Subarrays to Form a Target Array - https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int result = target.front();
        for(int i = 1; i < (int)target.size(); i++)
        {
            result += max(0, target[i] - target[i - 1]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenTarget = {1, 2, 3, 2, 1};
    int expectedAnswer = 3;
    assert(solution.minNumberOperations(givenTarget) == expectedAnswer);

    givenTarget = {3, 1, 5, 4, 2};
    expectedAnswer = 7;
    assert(solution.minNumberOperations(givenTarget) == expectedAnswer);

    return 0;
}
