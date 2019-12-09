//#503 Next Greater Element II - https://leetcode.com/problems/next-greater-element-ii/
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size());
        stack<int> prev;
        int n = nums.size();
        for(int i = n * 2 - 1; i >= 0; i--)
        {
            while(!prev.empty() && nums[prev.top()] <= nums[i % n])
                prev.pop();
            if(!prev.empty())
                result[i % n] = nums[prev.top()];
            else
                result[i % n] = -1;
            prev.push(i % n);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 1};
    vector<int> expected_answer = {2, -1, 2};
    assert(solution.nextGreaterElements(given_nums) == expected_answer);

    given_nums = {3, 8, 4, 1, 2};
    expected_answer = {8, -1, 8, 2, 3};
    assert(solution.nextGreaterElements(given_nums) == expected_answer);

    return 0;
}
