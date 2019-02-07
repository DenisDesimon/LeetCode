//#643 Maximum Average Subarray I - https://leetcode.com/problems/maximum-average-subarray-i/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int best = INT_MIN;
        int sum[(int)nums.size()];
        sum[0] = nums[0];
        for(int i = 1; i < (int)nums.size(); i++){
            sum[i] = (nums[i] + sum[i - 1]);
            if(i >= k)
              best = max(best, sum[i] - sum[i - k]);
        }
        best = max(best, sum[k-1]);
        return (double)best / k;
    }
};
int main()
{
Solution solution;
vector<int> given_nums = {1, 12, -5, -6, 50, 3};
int given_lenth = 4;
 double expected_answer = 12.75;
assert(solution.findMaxAverage(given_nums,given_lenth) == expected_answer);

given_nums = {-1};
given_lenth = 1;
expected_answer = -1;
assert(solution.findMaxAverage(given_nums,given_lenth) == expected_answer);


    return 0;
}
