//#442 Find All Duplicates in an Array - https://leetcode.com/problems/find-all-duplicates-in-an-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            int check_idx = abs(nums[i]) - 1;
            if(nums[check_idx] > 0)
                nums[check_idx] *= -1;
            else
                result.push_back(check_idx + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> expected_answer = {2, 3};
    assert(solution.findDuplicates(given_nums) == expected_answer);

    given_nums = {1, 1, 2, 2, 3, 4};
    expected_answer = {1, 2};
    assert(solution.findDuplicates(given_nums) == expected_answer);

    return 0;
}
