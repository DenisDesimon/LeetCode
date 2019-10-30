//#260 Single Number III - https://leetcode.com/problems/single-number-iii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for(int i = 0; i < (int)nums.size(); i += 2)
        {
            if(nums[i] != nums[i + 1] || i == (int)nums.size())
            {
                result.push_back(nums[i]);
                i--;
            }
        }
        return result;
    }
    vector<int> singleNumberBits(vector<int>& nums) {
        int two_num_bits = 0, first = 0, second = 0;
        for(auto num : nums)
        {
            two_num_bits ^= num;
        }
        int last_bit = two_num_bits & (~(two_num_bits - 1));
        for(auto num : nums)
        {
            if(num & last_bit)
                first ^= num;
            else
                second ^= num;
        }
        return {first, second};
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 1, 3, 2, 5};
    vector<int> expected_answer = {3, 5};
    assert(solution.singleNumber(given_nums) == expected_answer);
    assert(solution.singleNumberBits(given_nums) == expected_answer);

    given_nums = {5, 6, 7, 7, 5, 2, 1, 6};
    expected_answer = {1, 2};
    assert(solution.singleNumber(given_nums) == expected_answer);
    assert(solution.singleNumberBits(given_nums) == expected_answer);

    return 0;
}
