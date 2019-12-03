//#485 Max Consecutive Ones - https://leetcode.com/problems/max-consecutive-ones/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0;
        int start = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                result = max(result, i - start + 1);
            }
            else
                start = i + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 0, 1, 1, 1};
    int expected_answer = 3;
    assert(solution.findMaxConsecutiveOnes(given_nums) == expected_answer);

    given_nums = {0, 0, 0, 1};
    expected_answer = 1;
    assert(solution.findMaxConsecutiveOnes(given_nums) == expected_answer);

    return 0;
}
