//#152 Maximum Product Subarray - https://leetcode.com/problems/maximum-product-subarray/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int best = nums[0], max_product = 1, min_product = 1;
       for(int i = 0; i<(int)nums.size(); i++ )
       {
           int swap = max({nums[i], nums[i] * max_product, nums[i] * min_product});
           min_product = min({nums[i], nums[i] * max_product, nums[i] * min_product});
           max_product = swap;
           best=max(best, max_product);
       }
    return best;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 3, -2, 4};
    int expected_answer = 6;
    assert(solution.maxProduct(given_nums) == expected_answer);

    given_nums = {-2, 0, -1};
    expected_answer = 0;
    assert(solution.maxProduct(given_nums) == expected_answer);

    given_nums = {1, 2, -4, 6, 2, -2, 3, 6, -9};
    expected_answer = 3888;
    assert(solution.maxProduct(given_nums) == expected_answer);

        return 0;
    }

