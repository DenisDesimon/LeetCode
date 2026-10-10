//#2333 Minimum Sum of Squared Difference - https://leetcode.com/problems/minimum-sum-of-squared-difference/
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long result = 0;
        int k = k1 + k2;
        int maxDif = 0;
        int n = nums1.size();
        for(int i = 0; i < n; i++)
        {
            nums1[i] = abs(nums1[i] - nums2[i]);
            maxDif = max(maxDif, nums1[i]);
        }
        auto check = [&](int peak){
            long long sum = 0;
            for(auto &diff : nums1)
            {
                if(diff > peak)
                    sum += diff - peak;
                if(sum > k)
                    return false;
            }
            return true;
        };
        int left = 0, right = maxDif, peak = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(check(mid))
            {
                peak = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        for(auto &diff : nums1)
        {
            if(diff > peak)
                k -= diff - peak;
        }
        for(auto &diff : nums1)
        {
            if(diff > peak)
                diff = peak;
            if(k && diff)
            {
                diff--;
                k--;
            }
            result += (long long)diff * diff;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums1  = {1, 2, 3, 4};
    vector<int> givenNums2  = {2, 10, 20, 19};
    int givenK1 = 0;
    int givenK2 = 0;
    long long expectedAnswer = 579;
    assert(solution.minSumSquareDiff(givenNums1, givenNums2, givenK1, givenK2) == expectedAnswer);

    givenNums1  = {1, 4, 10, 12};
    givenNums2  = {5, 8, 6, 9};
    givenK1 = 1;
    givenK2 = 1;
    expectedAnswer = 43;
    assert(solution.minSumSquareDiff(givenNums1, givenNums2, givenK1, givenK2) == expectedAnswer);

    return 0;
}
