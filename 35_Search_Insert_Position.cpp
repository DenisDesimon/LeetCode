//#35 Search Insert Position - https://leetcode.com/problems/search-insert-position/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(right > left)
        {
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
// or just : return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 5, 6};
    int given_target = 7;
    int expected_answer = 4;
    assert(solution.searchInsert(given_nums, given_target) == expected_answer);

    given_nums = {1, 3, 5, 6};
    given_target = 3;
    expected_answer = 1;
    assert(solution.searchInsert(given_nums, given_target) == expected_answer);

    return 0;
}
