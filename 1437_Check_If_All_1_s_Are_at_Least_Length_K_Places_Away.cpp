//#1437 Check If All 1's Are at Least Length K Places Away - https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -k - 1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                if(i - prev - 1 < k)
                    return false;
                prev = i;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 0, 0, 0, 1, 0, 0, 1};
    int givenK = 2;
    bool expectedAnswer = true;
    assert(solution.kLengthApart(givenNums, givenK) == expectedAnswer);

    givenNums = {1, 0, 0, 1, 0, 1};
    givenK = 2;
    expectedAnswer = false;
    assert(solution.kLengthApart(givenNums, givenK) == expectedAnswer);

    return 0;
}
