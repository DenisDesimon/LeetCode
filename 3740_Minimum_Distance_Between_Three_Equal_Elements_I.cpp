//#3740 Minimum Distance Between Three Equal Elements I - https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> idxs(n + 1);
        int result = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            idxs[nums[i]].push_back(i);
        }
        for(auto &idx : idxs)
        {
            if(idx.size() > 2)
            {
                for(int i = 2; i < (int)idx.size(); i++)
                    result = min(result, idx[i] - idx[i - 1] + idx[i] - idx[i - 2] + idx[i - 1] - idx[i - 2]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 1, 1, 3};
    int expected_answer = 6;
    assert(solution.minimumDistance(givenNums) == expected_answer);

    givenNums = {1, 1, 2, 3, 2, 1, 2};
    expected_answer = 8;
    assert(solution.minimumDistance(givenNums) == expected_answer);

    return 0;
}
