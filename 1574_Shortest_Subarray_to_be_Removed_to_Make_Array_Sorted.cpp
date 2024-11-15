//#1574 Shortest Subarray to be Removed to Make Array Sorted - https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = (int)arr.size() - 1;
        while(right > 0 && arr[right] >= arr[right - 1])
            right--;
        int left = 0;
        int result =right;
        while(left < right && (left == 0 || arr[left] >= arr[left - 1]))
        {
            while(right < (int)arr.size() && arr[left] > arr[right])
                right++;
            result = min(result, right - left - 1);
            left++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {1, 2, 3, 10, 4, 2, 3, 5};
    int  expected_answer = 3;
    assert(solution.findLengthOfShortestSubarray(given_arr) == expected_answer);


    given_arr = {5, 4, 3, 2, 1};
    expected_answer = 4;
    assert(solution.findLengthOfShortestSubarray(given_arr) == expected_answer);

    return 0;
}
