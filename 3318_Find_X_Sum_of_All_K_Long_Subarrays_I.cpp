//#3318 Find X-Sum of All K-Long Subarrays I - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<pair<int, int>> countNum(51);
        vector<int> result;
        for(int i = 0; i < 51; i++)
            countNum[i].second = i;
        for(int i = 0; i < k - 1; i++)
            countNum[nums[i]].first++;
        for(int i = 0; i < n - k + 1; i++)
        {
            countNum[nums[i + k - 1]].first++;
            auto sortedNum = countNum;
            nth_element(sortedNum.begin(), sortedNum.begin() + x, sortedNum.end(), [](pair<int, int> &left, pair<int, int> right){return
                left.first == right.first ? left.second > right.second : left.first > right.first;});
            int curSum = 0;
            for(int t = 0; t < x; t++)
            {
                curSum += sortedNum[t].second * sortedNum[t].first;
            }
            result.push_back(curSum);
            countNum[nums[i]].first--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 2, 2, 3, 4, 2, 3};
    int givenK = 6;
    int givenN = 2;
    vector<int> expectedAnswer = {6, 10, 12};
    assert(solution.findXSum(givenNums, givenK, givenN) == expectedAnswer);

    givenNums = {3, 8, 7, 8, 7, 5};
    givenK = 2;
    givenN = 2;
    expectedAnswer = {11, 15, 15, 15, 12};
    assert(solution.findXSum(givenNums, givenK, givenN) == expectedAnswer);

    return 0;
}
