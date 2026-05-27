//#3936 Minimum Swaps to Move Zeros to End - https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count = 0;
        for(auto & num : nums)
        {
            if(num == 0)
                count++;
        }
        int result = 0;
        for(int i = nums.size() - 1; i > (int)nums.size() - 1 - count; i--)
        {
            if(nums[i] != 0)
                result++;
        }
        return result;
    }
};



int main()
{
    Solution solution;
    vector<int> givenNums = {0, 1, 0, 3, 12};
    int expectedAnswer = 2;
    assert(solution.minimumSwaps(givenNums) == expectedAnswer);

    givenNums  = {0, 1, 0, 2};
    expectedAnswer = 1;
    assert(solution.minimumSwaps(givenNums) == expectedAnswer);

    return 0;
}
