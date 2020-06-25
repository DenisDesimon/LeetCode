//#287 Find the Duplicate Number - https://leetcode.com/problems/find-the-duplicate-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = slow;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);
        slow = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 4, 2, 2};
    int expected_answer = 2;
    assert(solution.findDuplicate(given_nums) == expected_answer);

    given_nums = {3, 1, 3, 4, 2};
    expected_answer = 3;
    assert(solution.findDuplicate(given_nums) == expected_answer);

    return 0;
}
