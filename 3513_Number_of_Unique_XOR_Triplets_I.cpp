//#3513 Number of Unique XOR Triplets I - https://leetcode.com/problems/number-of-unique-xor-triplets-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 1, 2, 4};
    int expectedAnswer = 8;
    assert(solution.uniqueXorTriplets(givenNums) == expectedAnswer);

    givenNums = {3, 1, 2};
    expectedAnswer = 4;
    assert(solution.uniqueXorTriplets(givenNums) == expectedAnswer);

    return 0;
}
