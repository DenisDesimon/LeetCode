//#27 Remove Element - https://leetcode.com/problems/remove-element/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if(*iter == val)
            {
                nums.erase(iter);
                iter--;
            }
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 2, 2, 3};
    vector<int> expected_nums = {2, 2};
    int expected_answer = 2;
    int given_val = 3;
    assert(solution.removeElement(given_nums, given_val) == expected_answer && given_nums == expected_nums);

    return 0;
}
