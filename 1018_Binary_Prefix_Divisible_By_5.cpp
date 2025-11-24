//#1018 Binary Prefix Divisible By 5 - https://leetcode.com/problems/binary-prefix-divisible-by-5/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        long long cur = 0;
        for(auto &num : nums)
        {
            cur <<= 1;
            cur = (cur + num) % 5;
            result.push_back(cur == 0);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {0, 1, 1};
    vector<bool> expectedAnswer = {true, false, false};
    assert(solution.prefixesDivBy5(givenNums) == expectedAnswer);

    givenNums = {1, 1, 1};
    expectedAnswer = {false, false, false};
    assert(solution.prefixesDivBy5(givenNums) == expectedAnswer);

    return 0;
}
