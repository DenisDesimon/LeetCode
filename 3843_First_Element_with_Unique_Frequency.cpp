//#3843 First Element with Unique Frequency - https://leetcode.com/problems/first-element-with-unique-frequency/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> countNum;
        for(auto &num : nums)
            countNum[num]++;
        unordered_map<int, int> countFreq;
        for(auto &[num, count] : countNum)
        {
            countFreq[count]++;
        }
        for(auto &num : nums)
        {
            if(countFreq[countNum[num]] == 1)
                return num;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {10, 10, 20, 20};
    int expectedAnswer = -1;
    assert(solution.firstUniqueFreq(givenNums) == expectedAnswer);

    givenNums = {20, 20, 10, 30, 30, 30};
    expectedAnswer = 20;
    assert(solution.firstUniqueFreq(givenNums) == expectedAnswer);

    return 0;
}
