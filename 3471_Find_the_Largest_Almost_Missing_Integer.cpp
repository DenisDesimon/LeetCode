//#3471 Find the Largest Almost Missing Integer - https://leetcode.com/problems/find-the-largest-almost-missing-integer/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int count[51] = {0};
        int n = nums.size();
        for(auto num : nums)
            count[num]++;
        if(k == 1)
        {
            for(int i = 50; i >= 0; i--)
            {
                if(count[i] == 1)
                    return i;
            }
            return -1;
        }
        if(n == k)
        {
            for(int i = 50; i >= 0; i--)
            {
                if(count[i] != 0)
                    return i;
            }
        }
        int result = -1;
        if(count[nums.front()] == 1)
            result = nums.front();
        if(count[nums.back()] == 1)
            result = max(result, nums.back());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 9, 2, 1, 7};
    int givenK = 3;
    int expectedAnswer = 7;
    assert(solution.largestInteger(givenNums, givenK) == expectedAnswer);

    givenNums = {3, 9, 7, 2, 1, 7};
    givenK = 4;
    expectedAnswer = 3;
    assert(solution.largestInteger(givenNums, givenK) == expectedAnswer);


    return 0;
}
