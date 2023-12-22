//#2966 Divide Array Into Arrays With Max Difference - https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < (int)nums.size(); i += 3)
        {
            if(nums[i - 2] + k < nums[i])
                return {};
            result.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int given_k = 2;
    vector<vector<int>> expected_answer = {{1, 1, 3}, {3, 4, 5}, {7, 8, 9}};
    assert(solution.divideArray(given_nums, given_k) == expected_answer);

    given_nums = {1, 3, 3, 2, 7, 3};
    given_k = 3;
    expected_answer = {};
    assert(solution.divideArray(given_nums, given_k) == expected_answer);


    return 0;
}
