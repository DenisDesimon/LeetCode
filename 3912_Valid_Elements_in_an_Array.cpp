//#3912 Valid Elements in an Array - https://leetcode.com/problems/valid-elements-in-an-array/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        left.front() = nums.front();
        right.back() = nums.back();
        for(int i = 1; i < n - 1; i++)
        {
            left[i] = max(left[i - 1], nums[i]);
            right[n - i - 1] = max(right[n - i], nums[n - i - 1]);
        }
        vector<int> result;
        result.push_back(nums.front());
        for(int i = 1; i < n - 1; i++)
        {
            if(nums[i] > left[i - 1] || nums[i] > right[i + 1])
                result.push_back(nums[i]);
        }
        if(nums.size() > 1)
            result.push_back(nums.back());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 4, 2, 3, 2};
    vector<int> expectedAnswer = {1, 2, 4, 3, 2};
    assert(solution.findValidElements(givenNums) == expectedAnswer);

    givenNums = {5, 5, 5, 5};
    expectedAnswer = {5, 5};
    assert(solution.findValidElements(givenNums) == expectedAnswer);

    return 0;
}
