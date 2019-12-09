//#506 Relative Ranks - https://leetcode.com/problems/relative-ranks/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        pair<int, int> sort_nums[n];
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> result(n);
        for(int i = 0; i < n; i++)
        {
            sort_nums[i] = {nums[i], i};
        }
        sort(sort_nums, sort_nums + n, [](pair<int, int> a, pair<int, int> b){return a.first > b.first;});
        for(int i = 0; i < n; i++)
        {
            if(i < 3)
                result[sort_nums[i].second] = medals[i];
            else
                result[sort_nums[i].second] =  to_string(i + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 4, 3, 2, 1};
    vector<string> expected_answer = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
    assert(solution.findRelativeRanks(given_nums) == expected_answer);

    given_nums = {2015, 14, 2, 3, 567};
    expected_answer = {"Gold Medal", "Bronze Medal", "5", "4", "Silver Medal"};
    assert(solution.findRelativeRanks(given_nums) == expected_answer);

    return 0;
}
