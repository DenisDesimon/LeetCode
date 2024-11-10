//#3097 Shortest Subarray With OR at Least K II - https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int result = INT_MAX;
        int left = 0;
        int right = 0;
        vector<int> bitCount(32, 0);
        while(right < (int)nums.size())
        {
            updateBits(bitCount, nums[right], 1);
            while(left <= right && bitsToNum(bitCount) >= k)
            {
                result = min(result, right - left + 1);
                updateBits(bitCount, nums[left], -1);
                left++;
            }
            right++;
        }
        return result == INT_MAX ? -1 : result;
    }
private:
    void updateBits(vector<int> &bitCount, int num, int delta){
        for(int i = 0; i < 32; i++)
        {
            if((num >> i) & 1)
                bitCount[i] += delta;
        }
    }
    int bitsToNum(vector<int> &bitCount)
    {
        int num = 0;
        for(int i = 0; i < 32; i++)
        {
            if(bitCount[i])
                num |= 1 << i;
        }
        return num;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    int given_k = 3;
    int expected_answer = 1;
    assert(solution.minimumSubarrayLength(given_nums, given_k) == expected_answer);


    given_nums = {2, 1, 8};
    given_k = 10;
    expected_answer = 3;
    assert(solution.minimumSubarrayLength(given_nums, given_k) == expected_answer);

    return 0;
}
