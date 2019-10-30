//#268 Missing Number - https://leetcode.com/problems/missing-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int bits = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            bits ^= nums[i];
            bits ^= i;
        }
        bits ^= nums.size();
        return bits;
    }
};

int main()
{
    Solution solutuion;
    vector<int> given_nums = {3, 0, 1};
    int expected_answer = 2;
    assert(solutuion.missingNumber(given_nums) == expected_answer);

    given_nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    expected_answer = 8;
    assert(solutuion.missingNumber(given_nums) == expected_answer);

    return 0;
}
