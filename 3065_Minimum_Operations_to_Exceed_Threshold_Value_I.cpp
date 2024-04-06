//#3065 Minimum Operations to Exceed Threshold Value I - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        for(auto &num : nums)
        {
            if(num < k)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 2, 4, 9};
    int given_k = 1;
    int expected_answer = 0;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    given_nums = {2, 11, 10, 1, 3};
    given_k = 10;
    expected_answer = 3;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    return 0;
}
