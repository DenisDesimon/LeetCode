//40 Combination Sum II - https://leetcode.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    void find_sum(vector<int>& candidates, int target, vector<int>& cur_sum, vector<vector<int>>& result, int cur_index){
        if(target == 0)
        {
            result.push_back(cur_sum);
            return;
        }
        if(cur_index == (int)candidates.size())
            return;
        int num = candidates[cur_index];
        if(num > target)
            return;
        cur_sum.push_back(num);
        find_sum(candidates, target - num, cur_sum, result, cur_index + 1);
        cur_sum.pop_back();
        while(cur_index < (int)candidates.size() && num == candidates[cur_index])
            cur_index++;
        find_sum(candidates, target, cur_sum, result, cur_index);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur_sum;
        sort(candidates.begin(), candidates.end());
        find_sum(candidates, target, cur_sum, result, 0);
        return {result.begin(), result.end()};
    }
};

int main()
{
    Solution solution;
    vector<int> given_candidates = {10, 1, 2, 7, 6, 1, 5};
    int given_target = 8;
    vector<vector<int>> expected_answer = {{1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}};
    assert(solution.combinationSum2(given_candidates, given_target) == expected_answer);

    given_candidates = {2, 5, 2, 1, 2};
    given_target = 5;
    expected_answer = {{1, 2, 2}, {5}};
    assert(solution.combinationSum2(given_candidates, given_target) == expected_answer);

    return 0;
}
