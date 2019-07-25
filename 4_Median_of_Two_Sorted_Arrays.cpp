//#4 Median of Two Sorted Arrays - https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        if(n > m)
        {
            nums1.swap(nums2);
            swap(n, m);
        }
        int iMin = 0, iMax = n, mid = (n + m + 1) / 2;
        while(iMin <= iMax)
        {
            int i = (iMin + iMax) / 2;
            int j = mid - i;
            if(i > iMin && nums1[i - 1] > nums2[j])
                iMax--;
            else if(i < iMax && nums2[j - 1] >  nums1[i])
                iMin++;
            else
            {
                int max_left;
                if(i == 0)
                    max_left = nums2[j - 1];
                else if(j == 0)
                    max_left = nums1[i - 1];
                else
                    max_left = max(nums1[i - 1], nums2[j - 1]);
                if((n + m) % 2 == 1)
                    return max_left;
                int min_right;
                if(i == n)
                    min_right = nums2[j];
                else if(j == m)
                    min_right = nums1[i];
                else
                    min_right = min(nums1[i], nums2[j]);
                return ((double)min_right + (double)max_left) / 2;
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {2};
    vector<int> given_nums2 = {1, 3};
    int expected_answer = 2;
    assert(solution.findMedianSortedArrays(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {};
    given_nums2 = {1};
    expected_answer = 1;
    assert(solution.findMedianSortedArrays(given_nums1, given_nums2) == expected_answer);

    return 0;
}
