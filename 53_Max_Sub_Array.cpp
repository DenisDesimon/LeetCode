//#53 Maximum Subarray - https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int best = nums[0], sum=0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum = max(nums[i], sum+nums[i]);
            best = max(best, sum);
        }
        return best;
    }
};


int main()
{
Solution solution;
vector<int> given_nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
int expected_answer = 6;
assert(solution.maxSubArray(given_nums) == expected_answer);

given_nums = {-22};
expected_answer = -22;
assert(solution.maxSubArray(given_nums) == expected_answer);

given_nums = {-22,-10};
expected_answer = -10;
assert(solution.maxSubArray(given_nums) == expected_answer);

    return 0;
}
