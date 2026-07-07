//#3982 Sum of Integers with Maximum Digit Range - https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int mRange = 0;
        int result = 0;
        for(auto &num : nums)
        {
            int low = 9, high = 0;
            int cur = num;
            while(num)
            {
                low = min(low, num % 10);
                high = max(high, num % 10);
                num /= 10;
            }
            if(high - low == mRange)
                result += cur;
            else if(high - low > mRange)
            {
                result = cur;
                mRange = high - low;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5724, 111, 350};
    int expectedAnswer = 6074;
    assert(solution.maxDigitRange(givenNums) == expectedAnswer);

    givenNums = {90, 900};
    expectedAnswer = 990;
    assert(solution.maxDigitRange(givenNums) == expectedAnswer);

    return 0;
}
