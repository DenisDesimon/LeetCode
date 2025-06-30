//#3423 Maximum Difference Between Adjacent Elements in a Circular Array - https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = abs(nums.back() - nums.front());
        for(int i = 1; i < (int)nums.size(); i++)
            result = max(result, abs(nums[i] - nums[i - 1]));
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 4};
    int expected_answer = 3;
    assert(solution.maxAdjacentDistance(given_nums) == expected_answer);

    given_nums = {-5, -10, -5};
    expected_answer = 5;
    assert(solution.maxAdjacentDistance(given_nums) == expected_answer);

    return 0;
}
