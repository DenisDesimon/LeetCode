//#3432 Count Partitions with Even Sum Difference - https://leetcode.com/problems/count-partitions-with-even-sum-difference/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(auto &num : nums)
            sum += num;
        return (sum & 1) == 0 ? nums.size() - 1 : 0;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {10, 10, 3, 7, 6};
    int expectedAnswer = 4;
    assert(solution.countPartitions(givenNums) == expectedAnswer);

    givenNums = {2, 4, 6, 8};
    expectedAnswer = 3;
    assert(solution.countPartitions(givenNums) == expectedAnswer);

    return 0;
}
