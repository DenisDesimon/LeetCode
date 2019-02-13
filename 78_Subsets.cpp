//#78 Subsets - https://leetcode.com/problems/subsets/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1 << (int)nums.size());
        for(int b = 0; b < (1 << (int)nums.size()); b++){
            for(int i = 0; i < (int)nums.size(); i++){
                if(b & (1 << i))
                 result[b].push_back(nums[i]);
                                                            }
                                                        }
        return result;
    }
};
int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    vector<vector<int>> expected_answer = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
   assert(solution.subsets(given_nums) == expected_answer);
    return 0;
}
