//#3718 Smallest Missing Multiple of K - https://leetcode.com/problems/smallest-missing-multiple-of-k/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        const int maxNum = 101;
        bool count[maxNum] = {false};
        for(auto &num : nums)
            count[num] = true;
        int result = k;
        while(result < maxNum && count[result])
            result += k;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {8, 2, 3, 4, 6};
    int givenK = 2;
    int expectedAnswer = 10;
    assert(solution.missingMultiple(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 4, 7, 10, 15};
    givenK = 5;
    expectedAnswer = 5;
    assert(solution.missingMultiple(givenNums, givenK) == expectedAnswer);


    return 0;
}
