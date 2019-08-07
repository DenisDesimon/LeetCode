//#75 Sort Colors - https://leetcode.com/problems/sort-colors/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num_red = 0, num_white = 0, num_blue = 0;
        for(auto num : nums)
        {
            switch (num)
            {
                case 0 :
                    num_red++;
                    break;
                case 1 :
                    num_white++;
                    break;
                case 2 :
                    num_blue++;
                    break;

            }
        }
        fill(nums.begin(), nums.begin() + num_red, 0);
        fill(nums.begin() + num_red, nums.begin() + num_white + num_red, 1);
        fill(nums.begin() + num_red + num_white, nums.begin() + num_blue + num_red + num_white, 2);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 0, 2, 1, 1, 0};
    vector<int> expected_answer = {0, 0, 1, 1, 2, 2};
    solution.sortColors(given_nums);
    assert(given_nums == expected_answer);

    given_nums = {2, 2, 2, 2, 0, 0, 0};
    expected_answer = {0, 0, 0, 2, 2, 2, 2};
    solution.sortColors(given_nums);
    assert(given_nums == expected_answer);

    return 0;
}
