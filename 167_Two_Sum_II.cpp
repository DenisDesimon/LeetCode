//#167 Two Sum II - Input array is sorted - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = (int)numbers.size() - 1, left = 0;
        for(; left < right; left++)
        {
            while(numbers[left] + numbers[right] > target)
                right--;
            if(numbers[left] + numbers[right] == target)
                break;
        }
        return {left + 1, right + 1};
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2,7,11,15};
    int given_target = 9;
    vector<int>  expected_answer = {1, 2};
    assert(solution.twoSum(given_nums, given_target) == expected_answer);

    given_nums = {1, 3, 5, 10, 20};
    given_target = 15;
    expected_answer = {3, 4};
    assert(solution.twoSum(given_nums, given_target) == expected_answer);

    return 0;
}
