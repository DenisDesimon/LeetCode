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
        for(int b = 0; b < (1 << (int)nums.size()); b++){
            vector<int> subset;
            for(int i = 0; i < (int)nums.size(); i++){
                if(b & (1 << i))
                 subset.push_back(nums[i]);
                                                      }
            int g = 0;
            for(; g < (int)result.size(); g++)
            {
                if(subset == result[g])
                    break;
            }
            if(g == (int)result.size())
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
