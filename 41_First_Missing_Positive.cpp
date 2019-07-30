//41 First Missing Positive - https://leetcode.com/problems/first-missing-positive/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       for(int i = 0; i < (int)nums.size(); i++)
       {
           while(nums[i] >= 1 && nums[i] <= (int)nums.size() && nums[i] != nums[nums[i] - 1])
               swap(nums[i], nums[nums[i] - 1]);
       }
       for(int i = 1; i <= (int)nums.size(); i++)
       {
           if(nums[i - 1] != i)
               return i;
       }
       return nums.size() + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 4, -1, 1};
    int expected_answer = 2;
    assert(solution.firstMissingPositive(given_nums) == expected_answer);

    given_nums = {7, 8, 9, 11, 12};
    expected_answer = 1;
    assert(solution.firstMissingPositive(given_nums) == expected_answer);

    return 0;
}
