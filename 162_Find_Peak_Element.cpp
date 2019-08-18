//#162 Find Peak Element - https://leetcode.com/problems/find-peak-element/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 1};
    int expected_answer = 2;
    assert(solution.findPeakElement(given_nums) == expected_answer);

    given_nums = {1, 2, 1, 3, 5, 6, 4};
    expected_answer = 5;
    assert(solution.findPeakElement(given_nums) == expected_answer);

    return 0;
}
