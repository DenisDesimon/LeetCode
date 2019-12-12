//#1283 Find the Smallest Divisor Given a Threshold - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long sum = 0;
        int result;
        for(auto& num : nums)
        {
            sum += num;
        }
        long long left = sum / threshold;
        if(left == 0)
            left++;
        long long right = sum / (threshold / 2);
        while(left <= right)
        {
            int mid = (left + right) / 2;
            sum = 0;
            for(auto& num : nums)
                sum += (num - 1) / mid + 1;
            if(sum <= threshold)
            {
                result = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 5, 9};
    int given_thresh = 6;
    int expected_answer = 5;
    assert(solution.smallestDivisor(given_nums, given_thresh) == expected_answer);

    given_nums = {2, 3, 5, 7, 11};
    given_thresh = 11;
    expected_answer = 3;
    assert(solution.smallestDivisor(given_nums, given_thresh) == expected_answer);

    return 0;
}
