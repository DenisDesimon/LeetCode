//#1248 Count Number of Nice Subarrays - https://leetcode.com/problems/count-number-of-nice-subarrays/
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        deque<int> deq = {-1};
        int result = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] % 2)
                deq.push_back(i);
            if((int)deq.size() > k + 1)
                deq.pop_front();
            if((int)deq.size() == k + 1)
                result += deq[1] - (deq[0] + 1) + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 2, 1, 1};
    int given_k = 3;
    int expected_answer = 2;
    assert(solution.numberOfSubarrays(given_nums, given_k) == expected_answer);

    given_nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    given_k = 2;
    expected_answer = 16;
    assert(solution.numberOfSubarrays(given_nums, given_k) == expected_answer);

    return 0;
}
