//39 Combination Sum - https://leetcode.com/problems/combination-sum/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    void find_sum(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& cur_sum, int cur_index){
        if(target == 0)
        {
            result.push_back(cur_sum);
            return;
        }
        if(candidates[cur_index] > target)
            return;
        auto lower = lower_bound(candidates.begin() + cur_index, candidates.end(), target);
        int end = lower == candidates.end() ? candidates.size() : lower - candidates.begin() + 1;
        for(; cur_index < end; cur_index++)
        {
            cur_sum.push_back(candidates[cur_index]);
            find_sum(candidates, target - candidates[cur_index], result, cur_sum, cur_index);
            cur_sum.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> cur_sum;
        find_sum(candidates, target, result, cur_sum, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_candidates = {2, 3, 5};
    int given_target = 8;
    vector<vector<int>> expected_answer = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    assert(solution.combinationSum(given_candidates, given_target) == expected_answer);

    given_candidates = {2, 3, 6, 7};
    given_target = 7;
    expected_answer = {{2, 2, 3}, {7}};
    assert(solution.combinationSum(given_candidates, given_target) == expected_answer);

    return 0;
}
