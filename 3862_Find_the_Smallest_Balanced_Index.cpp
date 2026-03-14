//#3862 Find the Smallest Balanced Index - https://leetcode.com/problems/find-the-smallest-balanced-index/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(auto &num : nums)
            sum += num;
        long long product = 1;
        for(int i = n - 1; i > 0; i--)
        {
            sum -= nums[i];
            if(sum == product)
                return i;
            if(product > sum / nums[i])
                break;
            product *= nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 8, 2, 2, 5};
    int expectedAnswer = 2;
    assert(solution.smallestBalancedIndex(givenNums) == expectedAnswer);

    givenNums = {2, 1, 2};
    expectedAnswer = 1;
    assert(solution.smallestBalancedIndex(givenNums) == expectedAnswer);

    return 0;
}
