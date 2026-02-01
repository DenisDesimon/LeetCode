//#3830 Longest Alternating Subarray After Removing At Most One Element - https://leetcode.com/problems/longest-alternating-subarray-after-removing-at-most-one-element/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        auto cmp = [](int left, int right){return (left > right) - (left < right);};
        for(int i = 1; i < n; i++)
        {
            int sign = cmp(nums[i - 1], nums[i]);
            if(sign != 0)
            {
                if(i > 1 && cmp(nums[i - 2], nums[i - 1]) == -sign)
                    left[i] = left[i - 1] + 1;
                else
                    left[i] = 2;
            }
            result = max(result, left[i]);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            int sign = cmp(nums[i], nums[i + 1]);
            if(sign != 0)
            {
                if(i < n - 2 && cmp(nums[i + 1], nums[i + 2]) == -sign)
                    right[i] = right[i + 1] + 1;
                else
                    right[i] = 2;
            }
        }
        for(int i = 1; i < n - 1; i++)
        {
            int sign = cmp(nums[i - 1], nums[i + 1]);
            if(sign != 0)
            {
                int curLeft = (i > 1 && cmp(nums[i - 2], nums[i - 1]) == -sign) ? left[i - 1] : 1;
                int curRight = (i < n - 2 && cmp(nums[i + 1], nums[i + 2]) == -sign) ? right[i + 1] : 1;
                result = max(result, curLeft + curRight);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 2, 1, 2, 3, 2, 1};
    int expected_answer = 4;
    assert(solution.longestAlternating(givenNums) == expected_answer);

    givenNums = {2, 1, 3, 2};
    expected_answer = 4;
    assert(solution.longestAlternating(givenNums) == expected_answer);

    return 0;
}
