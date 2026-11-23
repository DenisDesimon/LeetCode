//#3420 Count Non-Decreasing Subarrays After K Operations - https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> leftGreaterPos;
        priority_queue<pair<int, int>> subMax;
        vector<vector<int>> rightPosDependents(n);
        vector<int> rightGreaterPos(n, n);
        long long result = 0;
        long long operations = 0;
        for(int left = 0, right = 0; right < n; right++)
        {
            while(!leftGreaterPos.empty() && nums[right] >= nums[leftGreaterPos.top()])
            {
                rightGreaterPos[leftGreaterPos.top()] = right;
                leftGreaterPos.pop();
            }
            if(!leftGreaterPos.empty())
                rightPosDependents[leftGreaterPos.top()].push_back(right);
            leftGreaterPos.push(right);
            subMax.push({nums[right], right});
            operations += max(0, subMax.top().first - nums[right]);
            while(operations > k)
            {
                for(auto &idx : rightPosDependents[left])
                {
                    operations -= (long long)(nums[left] - nums[idx]) * (min(rightGreaterPos[idx], right + 1) - idx);
                }
                left++;
            }
            while(!subMax.empty() && subMax.top().second < left)
                subMax.pop();
            result += right - left + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {6, 3, 1, 2, 4, 4};
    int givenK = 7;
    long long expectedAnswer = 17;
    assert(solution.countNonDecreasingSubarrays(givenNums, givenK) == expectedAnswer);

    givenNums = {6, 3, 1, 3, 6};
    givenK = 4;
    expectedAnswer = 12;
    assert(solution.countNonDecreasingSubarrays(givenNums, givenK) == expectedAnswer);

    return 0;
}
