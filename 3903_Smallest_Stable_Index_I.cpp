//#3903 Smallest Stable Index I - https://leetcode.com/problems/smallest-stable-index-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxNums(n), minNums(n);
        maxNums.front() = nums.front();
        minNums.back() = nums.back();
        for(int i = 1; i < n; i++)
        {
            maxNums[i] = max(maxNums[i - 1], nums[i]);
            minNums[n - i - 1] = min(minNums[n - i], nums[n - i - 1]);
        }
        for(int i = 0; i < n; i++)
        {
            if(maxNums[i] - minNums[i] <= k)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 0, 1, 4};
    int givenK = 3;
    int expectedAnswer = 3;
    assert(solution.firstStableIndex(givenNums, givenK) == expectedAnswer);

    givenNums = {3, 2, 1};
    givenK = 1;
    expectedAnswer = -1;
    assert(solution.firstStableIndex(givenNums, givenK) == expectedAnswer);


    return 0;
}
