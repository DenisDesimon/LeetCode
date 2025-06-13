//#2616 Minimize the Maximum Difference of Pairs - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
private:
    int countValidPairs(vector<int>& nums, int target){
        int result = 0;
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] <= target)
            {
                result++;
                i++;
            }
        }
        return result;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(countValidPairs(nums, mid) >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {10, 1, 2, 7, 1, 3};
    int given_p = 2;
    long long expected_answer = 1;
    assert(solution.minimizeMax(given_nums, given_p) == expected_answer);

    given_nums = {4, 2, 1, 2};
    given_p = 1;
    expected_answer = 0;
    assert(solution.minimizeMax(given_nums, given_p) == expected_answer);

    return 0;
}
