//#2154 Keep Multiplying Found Values by Two - https://leetcode.com/problems/keep-multiplying-found-values-by-two/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> unique(nums.begin(), nums.end());
        while(unique.count(original))
            original *= 2;
        return original;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 3, 6, 1, 12};
    int givenOriginal = 3;
    int expectedAnswer = 24;
    assert(solution.findFinalValue(givenNums, givenOriginal) == expectedAnswer);

    givenNums = {2, 7 ,9};
    givenOriginal = 4;
    expectedAnswer = 4;
    assert(solution.findFinalValue(givenNums, givenOriginal) == expectedAnswer);

    return 0;
}
