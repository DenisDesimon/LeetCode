//#3005 Count Elements With Maximum Frequency - https://leetcode.com/problems/count-elements-with-maximum-frequency/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> frequency(101);
        int count = 0, maxFreq = 0;
        for(auto &num : nums)
        {
            frequency[num]++;
            if(frequency[num] == maxFreq)
                count++;
            else if(frequency[num] > maxFreq)
            {
                count = 1;
                maxFreq = frequency[num];
            }
        }
        return count * maxFreq;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 2, 3, 1, 4};
    int expectedAnswer = 4;
    assert(solution.maxFrequencyElements(givenNums) == expectedAnswer);

    givenNums = {1, 2, 3, 4, 5};
    expectedAnswer = 5;
    assert(solution.maxFrequencyElements(givenNums) == expectedAnswer);

    return 0;
}
