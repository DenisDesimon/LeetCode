//#2537 Count the Number of Good Subarrays - https://leetcode.com/problems/count-the-number-of-good-subarrays/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> countNums;
        int right = 0, countPairs = 0;
        long long result = 0;
        for(int left = 0; left < n; left++)
        {
            while(right < n && countPairs < k)
            {
                countPairs += countNums[nums[right]];
                countNums[nums[right]]++;
                right++;
            }
            if(countPairs >= k)
                result += n - right + 1;
            countNums[nums[left]]--;
            countPairs -= countNums[nums[left]];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 1, 1, 1};
    int given_k = 10;
    int expected_answer = 1;
    assert(solution.countGood(given_nums, given_k) == expected_answer);

    given_nums = {3, 1, 4, 3, 2, 2, 4};
    given_k = 2;
    expected_answer = 4;
    assert(solution.countGood(given_nums, given_k) == expected_answer);

    return 0;
}
