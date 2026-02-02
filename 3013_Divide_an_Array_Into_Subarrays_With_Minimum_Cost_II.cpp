//#3013 Divide an Array Into Subarrays With Minimum Cost II - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long result = LLONG_MAX;
        int n = nums.size();
        set<pair<long long, long long>> windowMin, windowMax;
        long long sum = 0;
        for(int i = 1; i < n; i++)
        {
            sum += nums[i];
            windowMin.insert({nums[i], i});
            if((int)windowMin.size() >= k)
            {
                auto localMax = *windowMin.rbegin();
                windowMax.insert(localMax);
                sum -= localMax.first;
                windowMin.erase(localMax);
            }
            if(i - dist > 0)
            {
                result = min(result, sum);
                pair<long long, long long> outOfWindow = {nums[i - dist], i - dist};
                if(windowMin.count(outOfWindow))
                {
                    sum -= outOfWindow.first;
                    windowMin.erase(outOfWindow);
                    if(!windowMax.empty())
                    {
                        auto localMin = *windowMax.begin();
                        sum += localMin.first;
                        windowMin.insert(localMin);
                        windowMax.erase(localMin);
                    }
                }
                else
                {
                    windowMax.erase(outOfWindow);
                }
            }
        }
        return result + nums.front();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 2, 6, 4, 2};
    int givenK = 3;
    int givenDist = 3;
    int expectedAnswer = 5;
    assert(solution.minimumCost(givenNums, givenK, givenDist) == expectedAnswer);

    givenNums = {10, 1, 2, 2, 2, 1};
    givenK = 4;
    givenDist = 3;
    expectedAnswer = 15;
    assert(solution.minimumCost(givenNums, givenK, givenDist) == expectedAnswer);


    return 0;
}
