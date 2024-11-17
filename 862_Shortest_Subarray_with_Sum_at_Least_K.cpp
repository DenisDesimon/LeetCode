//#862 Shortest Subarray with Sum at Least K - https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix_sum(nums.size() + 1, 0);
        for(int i = 1; i <= (int)nums.size(); i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
        }
        deque<int> indexes;
        int result = INT_MAX;
        for(int i = 0; i <= (int)nums.size(); i++)
        {
            while(!indexes.empty() && prefix_sum[i] - prefix_sum[indexes.front()] >= k)
            {
                result = min(result, i - indexes.front());
                indexes.pop_front();
            }
            while(!indexes.empty() && prefix_sum[i] < prefix_sum[indexes.back()])
            {
                indexes.pop_back();
            }
            indexes.push_back(i);
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {84, -37, 32, 40, 95};
    int given_k = 167;
    int expected_answer = 3;
    assert(solution.shortestSubarray(given_nums, given_k) == expected_answer);

    given_nums = {2, -1, 2};
    given_k = 3;
    expected_answer = 3;
    assert(solution.shortestSubarray(given_nums, given_k) == expected_answer);

    return 0;
}
