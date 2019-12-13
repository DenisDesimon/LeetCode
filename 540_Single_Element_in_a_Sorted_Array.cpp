//#540 Single Element in a Sorted Array - https://leetcode.com/problems/single-element-in-a-sorted-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        for(auto& num : nums)
        {
            result ^= num;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int expected_asnwer = 2;
    assert(solution.singleNonDuplicate(given_nums) == expected_asnwer);

    given_nums = {3, 3, 7, 7, 10, 11, 11};
    expected_asnwer = 10;
    assert(solution.singleNonDuplicate(given_nums) == expected_asnwer);

    return 0;
}
