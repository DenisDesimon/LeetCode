//#494 Target Sum - https://leetcode.com/problems/target-sum/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int count(vector<int>& nums, int i, int cur_sum, int& S, int memo[][2001]){
        if(i == (int)nums.size())
        {
            if(cur_sum == S)
                return 1;
            else
                return 0;
        }
        else
        {
            if(memo[i][cur_sum + 1000] != INT_MIN)
            {
                return memo[i][cur_sum + 1000];
            }
            int add = count(nums, i + 1, cur_sum + nums[i], S, memo);
            int subtract = count(nums, i + 1, cur_sum - nums[i], S, memo);
            memo[i][cur_sum + 1000] = add + subtract;
            return memo[i][cur_sum + 1000];
        }

    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int memo[nums.size()][2001];
        for(auto array : memo)
            fill(array, array + 2001, INT_MIN);
        return count(nums, 0, 0, S, memo);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 1, 1, 1};
    int given_S = 3;
    int expected_answer = 5;
    assert(solution.findTargetSumWays(given_nums, given_S) == expected_answer);

    given_nums = {1};
    given_S = 1;
    expected_answer = 1;
    assert(solution.findTargetSumWays(given_nums, given_S) == expected_answer);

    return 0;
}
