//#611 Valid Triangle Number - https://leetcode.com/problems/valid-triangle-number/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int left = 0; left < (int)nums.size() - 2; left++)
        {
            int opposite = left + 2;
            for(int right = left + 1; right < (int)nums.size() - 1; right++)
            {
                while(opposite < (int)nums.size() && nums[left] + nums[right] > nums[opposite])
                    opposite++;
                if(opposite > right)
                    result += opposite - right - 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {0, 1, 1, 1};
    int expectedAnswer = 1;
    assert(solution.triangleNumber(givenNums) == expectedAnswer);

    givenNums = {4, 2, 3, 4};
    expectedAnswer = 4;
    assert(solution.triangleNumber(givenNums) == expectedAnswer);

    return 0;
}
