//#239 Sliding Window Maximum - https://leetcode.com/problems/sliding-window-maximum/
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> window;
       vector<int> result;
       for(int i = 0; i < (int)nums.size(); i++)
       {
           if(!window.empty() && window.front() == i - k)
               window.pop_front();
           while(!window.empty() && nums[window.back()] < nums[i])
               window.pop_back();
           window.push_back(i);
           if(i >= k - 1)
               result.push_back(nums[window.front()]);
       }
       return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int  given_k = 3;
    vector<int> expected_answer = {3, 3, 5, 5, 6, 7};
    assert(solution.maxSlidingWindow(given_nums, given_k) == expected_answer);

    given_nums = {1, 2, 2, 2, 5};
    given_k = 3;
    expected_answer = {2, 2, 5};
    assert(solution.maxSlidingWindow(given_nums, given_k) == expected_answer);

    return 0;
}
