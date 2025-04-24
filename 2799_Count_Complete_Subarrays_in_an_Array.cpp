//#2799 Count Complete Subarrays in an Array - https://leetcode.com/problems/count-complete-subarrays-in-an-array/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int n = nums.size();
        int countDistinct = distinct.size();
        int right = 0;
        int result = 0;
        for(int left = 0; left < n; left++)
        {
            while(right < n && (int)count.size() < countDistinct)
            {
                count[nums[right]]++;
                right++;
            }
            if((int)count.size() == countDistinct)
                result += n - right + 1;
            count[nums[left]]--;
            if(!count[nums[left]])
                count.erase(nums[left]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 1, 2, 2};
    int expected_answer = 4;
    assert(solution.countCompleteSubarrays(given_nums) == expected_answer);

    given_nums = {5, 5, 5, 5};
    expected_answer = 10;
    assert(solution.countCompleteSubarrays(given_nums) == expected_answer);

    return 0;
}
