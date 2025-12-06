//#3578 Count Partitions With Max-Min Difference at Most K - https://leetcode.com/problems/count-partitions-with-max-min-difference-at-most-k/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        deque<int> maxPart, minPart;
        dp[0] = 1;
        prefix[0] = 1;
        int right = 0;
        for(int left = 0; left < n; left++)
        {
            while(!maxPart.empty() && nums[left] > maxPart.back())
                maxPart.pop_back();
            maxPart.push_back(nums[left]);
            while(!minPart.empty() && nums[left] < minPart.back())
                minPart.pop_back();
            minPart.push_back(nums[left]);
            while(!maxPart.empty() && !minPart.empty() && maxPart.front() - minPart.front() > k)
            {
                if(nums[right] == maxPart.front())
                    maxPart.pop_front();
                if(nums[right] == minPart.front())
                    minPart.pop_front();
                right++;
            }
            dp[left + 1] = (prefix[left] - (right > 0 ? prefix[right - 1] : 0) + mod) % mod;
            prefix[left + 1] = (prefix[left] + dp[left + 1]) % mod;
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {9, 4, 1, 3, 7};
    int givenK = 4;
    int expectedAnswer = 6;
    assert(solution.countPartitions(givenNums, givenK) == expectedAnswer);

    givenNums = {3, 3, 4};
    givenK = 0;
    expectedAnswer = 2;
    assert(solution.countPartitions(givenNums, givenK) == expectedAnswer);

    return 0;
}
