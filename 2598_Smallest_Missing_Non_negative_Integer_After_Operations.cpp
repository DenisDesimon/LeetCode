//#2598 Smallest Missing Non-negative Integer After Operations - https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> countRemainders(value + 1, 0);
        for(auto &num : nums)
            countRemainders[(num % value + value) % value]++;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(countRemainders[i % value] < i / value + 1)
                return i;
        }
        return nums.size();
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, -10, 7, 13, 6, 8};
    int givenValue = 5;
    int expectedAnswer = 4;
    assert(solution.findSmallestInteger(givenNums, givenValue) == expectedAnswer);

    givenNums = {1, -10, 7, 13, 6, 8};
    givenValue = 7;
    expectedAnswer = 2;
    assert(solution.findSmallestInteger(givenNums, givenValue) == expectedAnswer);


    return 0;
}
