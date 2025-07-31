//#3202 Find the Maximum Length of Valid Subsequence II - https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int result = 0;
        vector<vector<int>> subLengths(k, vector<int>(k));
        for(auto &num : nums)
        {
            int mod = num % k;
            for(int prevNum = 0; prevNum < k; prevNum++)
            {
                subLengths[prevNum][mod] = subLengths[mod][prevNum] + 1;
                result = max(result, subLengths[prevNum][mod]);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> givenNums = {1, 2, 3, 4, 5};
    int givenK = 2;
    int expectedAnswer = 5;
    assert(solution.maximumLength(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 4, 2, 3, 1, 4};
    givenK = 3;
    expectedAnswer = 4;
    assert(solution.maximumLength(givenNums, givenK) == expectedAnswer);

    return 0;
}
