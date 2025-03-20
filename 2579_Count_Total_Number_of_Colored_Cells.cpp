//#1760 Minimum Limit of Balls in a Bag - https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;


class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            int operationsCount = 0;
            for(auto &num : nums)
            {
                operationsCount += (num - 1) / mid;
                if(operationsCount > maxOperations)
                    break;
            }
            operationsCount <= maxOperations ? high = mid : low = mid + 1;
        }
        return high;
    }
};


int main()
{
    Solution solution;
    vector<int> given_nums = {2, 4, 8, 2};
    int given_maxOperations = 4;
    int expected_answer = 2;
    assert(solution.minimumSize(given_nums, given_maxOperations) == expected_answer);

    given_nums = {9};
    given_maxOperations = 2;
    expected_answer = 3;
    assert(solution.minimumSize(given_nums, given_maxOperations) == expected_answer);

    return 0;
}
