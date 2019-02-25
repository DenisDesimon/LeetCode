//#238 Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        for(int i = 1; i < n; i++)
            result[i] = result[i - 1] * nums[i - 1];
        for(int i = n - 1, product = 1; i >= 0; product *= nums[i--])
            result[i] *= product;

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 4};
    vector<int>  expected_answer = {24, 12, 8, 6};
    assert(solution.productExceptSelf(given_nums) == expected_answer);

    given_nums = {0, 5, 2};
    expected_answer = {10, 0, 0};
    assert(solution.productExceptSelf(given_nums) == expected_answer);

    return 0;
}
