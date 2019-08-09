//#80 Remove Duplicates from Sorted Array II - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count_num = 1;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i - 1] == nums[i])
                count_num++;
            else
                count_num = 1;
            if(count_num >= 3)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int expected_answer = 7;
    vector<int> expected_nums = {0, 0, 1, 1, 2, 3, 3};
    assert(solution.removeDuplicates(given_nums) == expected_answer && given_nums == expected_nums);

    given_nums = {1, 1, 1, 2, 2, 3};
    expected_answer = 5;
    expected_nums = {1, 1, 2, 2, 3};
    assert(solution.removeDuplicates(given_nums) == expected_answer && given_nums == expected_nums);

    return 0;
}
