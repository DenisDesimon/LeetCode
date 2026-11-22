//#3041 Maximize Consecutive Elements in an Array After Modification - https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> numCount;
        int result = 1;
        for(auto &num : nums)
        {
            if(numCount.count(num))
                numCount[num + 1] = numCount[num] + 1;
            else
            {
                numCount[num] = 1;
                numCount[num + 1] = 1;
            }
            if(numCount.count(num - 1))
                numCount[num] = numCount[num - 1] + 1;
            result = max({result, numCount[num], numCount[num + 1]});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 1, 5, 1, 1};
    int expectedAnswer = 3;
    assert(solution.maxSelectedElements(givenNums) == expectedAnswer);

    givenNums = {1, 4, 7, 10};
    expectedAnswer = 1;
    assert(solution.maxSelectedElements(givenNums) == expectedAnswer);

    return 0;
}
