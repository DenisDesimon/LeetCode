//#3852 Smallest Pair With Different Frequencies - https://leetcode.com/problems/smallest-pair-with-different-frequencies/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int count[101] = {0};
        for(auto &num : nums)
        {
            count[num]++;
        }
        vector<int> result;
        int i = 0;
        for(; i < 101; i++)
        {
            if(count[i])
            {
                result.push_back(i);
                break;
            }
        }
        for(; i < 101; i++)
        {
            if(count[i] && count[i] != count[result.front()])
            {
                result.push_back(i);
                break;
            }
        }
        return (int)result.size() > 1 ? result : vector<int>(2, -1);
    }
};


int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 2, 2, 3, 4};
    vector<int> expectedAnswer = {1, 3};
    assert(solution.minDistinctFreqPair(givenNums) == expectedAnswer);

    givenNums = {7};
    expectedAnswer = {-1, -1};
    assert(solution.minDistinctFreqPair(givenNums) == expectedAnswer);

    return 0;
}
