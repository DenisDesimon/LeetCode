//#3909 Compare Sums of Bitonic Parts - https://leetcode.com/problems/compare-sums-of-bitonic-parts/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sum = nums.front();
        int i = 1;
        while(nums[i] > nums[i - 1])
            sum += nums[i++];
        sum -= nums[i - 1];
        for(; i < (int)nums.size(); i++)
            sum -= nums[i];
        return sum > 0 ? 0 : sum == 0 ? -1 : 1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 2, 1};
    int expectedAnswer = 1;
    assert(solution.compareBitonicSums(givenNums) == expectedAnswer);

    givenNums = {2, 4 ,5, 2};
    expectedAnswer = 0;
    assert(solution.compareBitonicSums(givenNums) == expectedAnswer);

    return 0;
}
