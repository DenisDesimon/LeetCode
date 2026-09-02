//#3875 Construct Uniform Parity Array I - https://leetcode.com/problems/construct-uniform-parity-array-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 3};
    bool expectedAnswer = true;
    assert(solution.uniformArray(givenNums) == expectedAnswer);

    givenNums = {4, 6};
    expectedAnswer = true;
    assert(solution.uniformArray(givenNums) == expectedAnswer);


    return 0;
}
