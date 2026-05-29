//#3940 Limit Occurrences in Sorted Array - https://leetcode.com/problems/limit-occurrences-in-sorted-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int cur = i + 1;
            result.push_back(nums[i]);
            while(cur < n && nums[i] == nums[cur])
            {
                if(cur - i + 1 <= k)
                    result.push_back(nums[i]);
                cur++;
            }
            i = cur - 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 1, 2, 2, 3};
    int givenK = 2;
    vector<int> expectedAnswer = {1, 1, 2, 2, 3};
    assert(solution.limitOccurrences(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 2, 3};
    givenK = 1;
    expectedAnswer = {1, 2, 3};
    assert(solution.limitOccurrences(givenNums, givenK) == expectedAnswer);

    return 0;
}
