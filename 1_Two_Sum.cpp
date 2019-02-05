//#1 Two Summ - https://leetcode.com/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left, right;
        unordered_map<int,int> HashMap;

        for(int index = 0; index < (int)nums.size(); index++){
            int difference = target - nums[index];

            if(HashMap.count(difference)){
            left = HashMap[difference];
            right = index;
            break;
            }

            HashMap[nums[index]] = index;
        }

        return {left,right};
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {2, 7, 11, 15};
    int given_target = 9;
    vector<int> expected_answer = {0, 1};

    assert(solution.twoSum(given_nums,given_target) == expected_answer);

    given_nums = {5, 11, 22, 2};
    given_target = 13;
    expected_answer = {1, 3};

    assert(solution.twoSum(given_nums,given_target) == expected_answer);

    return 0;
}
