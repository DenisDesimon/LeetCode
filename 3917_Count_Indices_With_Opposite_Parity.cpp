//#3917 Count Indices With Opposite Parity - https://leetcode.com/problems/count-indices-with-opposite-parity/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int countOdd = 0;
        int n = nums.size();
        vector<int> result(n);
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] & 1)
            {
                result[i] = (n - 1 - i - countOdd);
                countOdd++;
            }
            else
                result[i] = countOdd;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3, 4};
    vector<int> expectedAnswer = {2, 1 ,1, 0};
    assert(solution.countOppositeParity(givenNums) == expectedAnswer);

    givenNums = {1};
    expectedAnswer = {0};
    assert(solution.countOppositeParity(givenNums) == expectedAnswer);

    return 0;
}
