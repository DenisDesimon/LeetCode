//#3731 Find Missing Elements - https://leetcode.com/problems/find-missing-elements/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        bool count[101] = {false};
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(auto &num : nums)
        {
            count[num] = true;
            maxNum = max(maxNum, num);
            minNum = min(minNum, num);
        }
        for(int i = minNum; i <= maxNum; i++)
        {
            if(!count[i])
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 4, 2, 5};
    vector<int> expectedAnswer = {3};
    assert(solution.findMissingElements(givenNums) == expectedAnswer);

    givenNums = {5, 1};
    expectedAnswer = {2, 3, 4};
    assert(solution.findMissingElements(givenNums) == expectedAnswer);

    return 0;
}
