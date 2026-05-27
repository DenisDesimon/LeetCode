//#3937 Minimum Operations to Make Array Modulo Alternating I - https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int result = INT_MAX;
        for(int x = 0; x < k; x++)
        {
            for(int y = 0; y < k; y++)
            {
                if(x == y)
                    continue;
                int cur = 0;
                for(int i = 0; i < n; i++)
                {
                    int remainder = nums[i] % k;
                    if(i % 2)
                    {
                        int dist = abs(remainder - y);
                        cur += min(dist, k - dist);
                    }
                    else
                    {
                        int dist = abs(remainder - x);
                        cur += min(dist, k - dist);
                    }
                }
                result = min(result, cur);
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 4, 2, 8};
    int givenK = 3;
    int expectedAnswer = 2;
    assert(solution.minOperations(givenNums, givenK) == expectedAnswer);

    givenNums  = {1, 1, 1};
    givenK = 3;
    expectedAnswer = 1;
    assert(solution.minOperations(givenNums, givenK) == expectedAnswer);

    return 0;
}
