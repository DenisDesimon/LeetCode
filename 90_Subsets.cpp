//#90 Subsets II - https://leetcode.com/problems/subsets-ii/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < (1 << (int)nums.size()); i++)
        {
            vector<int> subset;
            for(int j = 0; j < (int)nums.size(); j++)
            {
                if(i & (1 << j))
                {
                    subset.push_back(nums[j]);
                }
            }
            if(count(result.begin(), result.end(), subset) == 0)
                result.push_back(subset);
        }
        return result;

    }
};
int main()
{

    Solution solution;
    vector<int> given_nums = {1, 2, 2};
    vector<vector<int>> expected_answer = {{}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}};
    assert(solution.subsetsWithDup(given_nums) == expected_answer);

    return 0;
}
