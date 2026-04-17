//#3761 Minimum Absolute Distance Between Mirror Pairs - https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int reverseNum(int num)
    {
        int result = 0;
        while(num)
        {
            result *= 10;
            result += num % 10;
            num /= 10;
        }
        return result;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> numPos;
        int n = nums.size();
        int result = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(numPos.count(nums[i]))
                result = min(result, i - numPos[nums[i]]);
            numPos[reverseNum(nums[i])] = i;
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {12, 21, 45, 33, 54};
    int expectedAnswer = 1;
    assert(solution.minMirrorPairDistance(givenNums) == expectedAnswer);

    givenNums = {120, 21};
    expectedAnswer = 1;
    assert(solution.minMirrorPairDistance(givenNums) == expectedAnswer);

    return 0;
}
