//#658 Find K Closest Elements - https://leetcode.com/problems/find-k-closest-elements/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lower = lower_bound(arr.begin(), arr.end(), x);
        int idx = lower - arr.begin();
        if(idx > 0 && x - arr[idx - 1] < arr[idx] - x)
            idx = idx - 1;
        int left = idx, right = idx;
        k -= 1;
        while(k)
        {
            if(left > 0 && right < (int)arr.size() - 1)
            {
                if(x - arr[left - 1] <= arr[right + 1] - x)
                    left--;
                else
                    right++;
            }
            else if(left <= 0)
                right++;
            else
                left--;
            k--;
        }
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 0, 1, 2, 3, 3, 4, 7, 7, 8};
    int given_k = 3;
    int given_x = 5;
    vector<int> expected_answer = {3, 3, 4};
    assert(solution.findClosestElements(given_nums, given_k, given_x) == expected_answer);

    given_nums = {1, 2, 3, 4, 5};
    given_k = 4;
    given_x = -1;
    expected_answer = {1, 2, 3, 4};
    assert(solution.findClosestElements(given_nums, given_k, given_x) == expected_answer);

    return 0;
}
