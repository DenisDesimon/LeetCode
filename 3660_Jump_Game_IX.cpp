//#3660 Jump Game IX - https://leetcode.com/problems/jump-game-ix/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n), result(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], nums[i]);
        suffix[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            suffix[i] = min(suffix[i + 1], nums[i]);
        result[n - 1] = prefix[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            if(prefix[i] > suffix[i + 1])
                result[i] = result[i + 1];
            else
                result[i] = prefix[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 1, 3};
    vector<int> expectedAnswer = {2, 2, 3};
    assert(solution.maxValue(givenNums) == expectedAnswer);

    givenNums = {2, 3, 1};
    expectedAnswer = {3, 3, 3};
    assert(solution.maxValue(givenNums) == expectedAnswer);

    return 0;
}
