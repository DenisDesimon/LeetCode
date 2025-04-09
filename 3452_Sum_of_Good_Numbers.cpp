//#3452 Sum of Good Numbers - https://leetcode.com/problems/sum-of-good-numbers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


class Solution{
public:
    int sumOfGoodNumbers(vector<int> nums, int k){
        int result = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            int left = i - k >= 0 ? nums[i - k] : INT_MIN;
            int right = i + k < (int)nums.size() ? nums[i + k] : INT_MIN;
            if(nums[i] > left && nums[i] > right)
                result += nums[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 2, 1, 5, 4};
    int given_k = 2;
    int expected_answer = 12;
    assert(solution.sumOfGoodNumbers(given_nums, given_k) == expected_answer);

    given_nums = {2, 1};
    given_k = 1;
    expected_answer = 2;
    assert(solution.sumOfGoodNumbers(given_nums, given_k) == expected_answer);

    return 0;
}
