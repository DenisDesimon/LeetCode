//#456 132 Pattern - https://leetcode.com/problems/132-pattern/
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if((int)nums.size() < 3)
            return false;
        int min_num[nums.size()];
        min_num[0] = nums[0];
        stack<int> hash;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            min_num[i] = min(min_num[i - 1], nums[i]);
        }
        for(int i = nums.size() - 1; i >= 1; i--)
        {
            while(!hash.empty() && min_num[i] >= hash.top())
                hash.pop();
            if(!hash.empty() && nums[i] > hash.top())
                return true;
            hash.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 0, 1, -4, -3};
    bool expected_answer = false;
    assert(solution.find132pattern(given_nums) == expected_answer);

    given_nums = {3, 1, 4, 2};
    expected_answer = true;
    assert(solution.find132pattern(given_nums) == expected_answer);

    return 0;
}
