//#2778 Sum of Squares of Special Elements  - https://leetcode.com/problems/sum-of-squares-of-special-elements/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(n % (i + 1) == 0)
                sum += nums[i] * nums[i];
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 3, 4};
    int expectedAnswer = 21;
    assert(solution.sumOfSquares(givenNums) == expectedAnswer);

    givenNums  = {2, 7, 1, 19, 18, 3};
    expectedAnswer = 63;
    assert(solution.sumOfSquares(givenNums) == expectedAnswer);

    return 0;
}
