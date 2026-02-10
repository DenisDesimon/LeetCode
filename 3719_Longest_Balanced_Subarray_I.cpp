//#3719 Longest Balanced Subarray I - https://leetcode.com/problems/longest-balanced-subarray-i/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_set<int> countOdd;
            unordered_set<int> countEven;
            for(int j = i; j < n; j++)
            {
                if(nums[j] % 2)
                    countOdd.insert(nums[j]);
                else
                    countEven.insert(nums[j]);
                if(countEven.size() == countOdd.size())
                    result = max(result, j - i + 1);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 5, 4, 3};
    int expectedAnswer = 4;
    assert(solution.longestBalanced(givenNums) == expectedAnswer);

    givenNums = {1, 2, 3, 2};
    expectedAnswer = 3;
    assert(solution.longestBalanced(givenNums) == expectedAnswer);

    return 0;
}
