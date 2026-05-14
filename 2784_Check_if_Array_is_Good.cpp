//#2784 Check if Array is Good - https://leetcode.com/problems/check-if-array-is-good/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 1);
        count.back() = 2;
        for(auto &num : nums)
        {
            if(num > n)
                return false;
            count[num]--;
            if(count[num] < 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {3, 4, 4, 1, 2, 1};
    bool expectedAnswer = false;
    assert(solution.isGood(givenNums) == expectedAnswer);

    givenNums = {1, 3, 3, 2};
    expectedAnswer = true;
    assert(solution.isGood(givenNums) == expectedAnswer);

    return 0;
}
