//#3254 Find the Power of K-Size Subarrays I - https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1)
            return nums;
        vector<int> result(nums.size() - k  +  1, -1);
        int counter = 1;
        for(int i = 1; i < (int)nums.size(); i++)
        {
            if(nums[i] != nums[i - 1] + 1)
                counter = 0;
            counter++;
            if(counter >= k)
                result[i - k + 1] = nums[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 4, 3, 2, 5};
    int given_k = 3;
    vector<int> expected_answer = {3, 4, -1, -1, -1};
    assert(solution.resultsArray(given_nums, given_k) == expected_answer);

    given_nums = {3, 2, 3, 2, 3, 2};
    given_k = 2;
    expected_answer = {-1, 3, -1, 3, -1};
    assert(solution.resultsArray(given_nums, given_k) == expected_answer);


    return 0;
}
