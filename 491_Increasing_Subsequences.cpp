//#491 Increasing Subsequences - https://leetcode.com/problems/increasing-subsequences/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<vector<vector<int>>> memo(n);
        for(int i = 0; i < n; i++)
        {
            bool is_equal = false;
            for(int j = i - 1; !is_equal && j >= 0; j--)
            {
                if(nums[j] > nums[i])
                    continue;
                else if(nums[j] == nums[i])
                    is_equal = true;
                vector<vector<int>> last_seq = memo[j];
                for(auto& sub_seq : last_seq)
                {
                    sub_seq.push_back(nums[i]);
                    result.push_back(sub_seq);
                }
                memo[i].insert(memo[i].end(), last_seq.begin(), last_seq.end());
            }
            if(!is_equal)
                memo[i].push_back({nums[i]});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 6, 7, 7};
    vector<vector<int>> expected_answer = {{4, 6}, {4, 6, 7}, {6, 7}, {4, 7}, {4, 6, 7, 7}, {6, 7, 7}, {4, 7, 7}, {7, 7}};
    assert(solution.findSubsequences(given_nums) == expected_answer);

    return 0;
}
