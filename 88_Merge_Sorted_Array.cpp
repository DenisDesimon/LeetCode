//#88 Merge Sorted Array - https://leetcode.com/problems/merge-sorted-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums1.empty() || nums2.empty())
            return;
        auto upper_low = upper_bound(nums1.begin(), nums1.begin() + m, nums2[0]);
        auto upper_high = upper_bound(nums1.begin(), nums1.begin() + m, nums2[n - 1]);
        if(upper_high == nums1.begin())
        {
            copy(nums1.begin(), nums1.begin() + m, nums1.end() - m);
            copy(nums2.begin(), nums2.end(), nums1.begin());
        }
        else if(upper_low == nums1.begin() + m)
        {
            copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        }
        else
        {
            auto temp = upper_low;
            while(upper_low < upper_high)
            {
                nums2.insert(upper_bound(nums2.begin(), nums2.end(), *upper_low), *upper_low);
                upper_low++;
            }
            copy(upper_high, nums1.begin() + m, nums1.end() - (nums1.begin() + m - upper_high));
            copy(nums2.begin(), nums2.end(), temp);
        }
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {1, 2, 4, 5, 6, 0};
    vector<int> given_nums2 = {1};
    vector<int> expected_answer = {1, 1, 2, 4, 5, 6};
    int given_m = 5, given_n = 1;
    solution.merge(given_nums1, given_m, given_nums2, given_n);
    assert(given_nums1 == expected_answer);

    given_nums1 = {1, 2, 3, 0, 0, 0};
    given_nums2 = {2, 5, 6};
    expected_answer = {1, 2, 2, 3, 5, 6};
    given_m = 3, given_n = 3;
    solution.merge(given_nums1, given_m, given_nums2, given_n);
    assert(given_nums1 == expected_answer);

    return 0;
}
