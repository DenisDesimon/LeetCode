//#3847 Find the Score Difference in a Game - https://leetcode.com/problems/find-the-score-difference-in-a-game/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0, second = 0;
        bool isFirstActive = true;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] % 2)
                isFirstActive = !isFirstActive;
            if(i % 6 == 5)
                isFirstActive = !isFirstActive;
            if(isFirstActive)
                first += nums[i];
            else
                second += nums[i];
        }
        return first - second;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3};
    int expectedAnswer = 0;
    assert(solution.scoreDifference(givenNums) == expectedAnswer);

    givenNums = {2, 4, 2, 1, 2, 1};
    expectedAnswer = 4;
    assert(solution.scoreDifference(givenNums) == expectedAnswer);

    return 0;
}
