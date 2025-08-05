//#2210 Count Hills and Valleys in an Array - https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        for(int i = 1; i < (int)nums.size() - 1; )
        {
            int right = i + 1;
            while(right < (int)nums.size() - 1 && nums[i] == nums[right])
                right++;
            if(nums[i - 1] < nums[i] && nums[i] > nums[right])
                cnt++;
            else if(nums[i - 1] > nums[i] && nums[i] < nums[right])
                cnt++;
            i = right;
        }
        return cnt;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 4, 1, 1, 6, 5};
    int expectedAnswer = 3;
    assert(solution.countHillValley(givenNums) == expectedAnswer);

    givenNums = {6, 6, 5, 5, 4, 1};
    expectedAnswer = 0;
    assert(solution.countHillValley(givenNums) == expectedAnswer);

    return 0;
}
