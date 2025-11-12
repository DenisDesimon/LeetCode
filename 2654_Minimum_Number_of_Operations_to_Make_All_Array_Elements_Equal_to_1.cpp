//#2654 Minimum Number of Operations to Make All Array Elements Equal to 1 - https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int gcd(int left, int right){
        while(right)
        {
            int temp = right;
            right = left % right;
            left = temp;
        }
        return left;
    }
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int totalGcd = 0;
        int countOnes = 0;
        for(auto &num : nums)
        {
            if(num == 1)
                countOnes++;
            totalGcd = gcd(totalGcd, num);
        }
        if(totalGcd > 1)
            return -1;
        if(countOnes)
            return n - countOnes;
        int minLength = n;
        for(int i = 0; i < n; i++)
        {
            totalGcd = 0;
            for(int j = i; j < n; j++)
            {
                totalGcd = gcd(totalGcd, nums[j]);
                if(totalGcd == 1)
                {
                    minLength = min(j - i + 1, minLength);
                    break;
                }
            }
        }
        return n + minLength - 2;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 6, 3, 4};
    int expectedAnswer = 4;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    givenNums = {6, 10, 15};
    expectedAnswer = 4;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    return 0;
}
