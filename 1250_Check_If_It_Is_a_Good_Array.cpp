//#1250 Check If It Is a Good Array - https://leetcode.com/problems/check-if-it-is-a-good-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int greater_common_divisor(int a, int b){
        if(b == 0)
            return a;
        return greater_common_divisor(b, a % b);
    }
public:
    bool isGoodArray(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 1)
            return true;
        int gcd = nums[0];
        for(int i = 1; i < (int)nums.size(); i++)
        {
            gcd = greater_common_divisor(gcd, nums[i]);
            if(gcd == 1)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {12, 5, 7, 23};
    bool expected_answer = true;
    assert(solution.isGoodArray(given_nums) == expected_answer);

    given_nums = {3, 6};
    expected_answer = false;
    assert(solution.isGoodArray(given_nums) == expected_answer);

    return 0;
}
