//#3190 Find Minimum Operations to Make All Elements Divisible by Three - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for(auto &num : nums)
            result += num % 3 ? 1 : 0;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4};
    int expectedAnswer = 3;
    assert(solution.minimumOperations(givenNums) == expectedAnswer);

    givenNums = {3, 6, 9};
    expectedAnswer = 0;
    assert(solution.minimumOperations(givenNums) == expectedAnswer);

    return 0;
}
