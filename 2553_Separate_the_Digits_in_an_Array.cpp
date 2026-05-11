//#2553 Separate the Digits in an Array - https://leetcode.com/problems/separate-the-digits-in-an-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for(auto &num : nums)
        {
            int start = result.size();
            int cur = num;
            while(cur)
            {
                result.insert(result.begin() + start, cur % 10);
                cur /= 10;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {13, 25, 83, 77};
    vector<int> expectedAnswer = {1, 3, 2, 5, 8, 3, 7, 7};
    assert(solution.separateDigits(givenNums) == expectedAnswer);

    givenNums = {7, 1, 3, 9};
    expectedAnswer = {7, 1 ,3, 9};
    assert(solution.separateDigits(givenNums) == expectedAnswer);

    return 0;
}
