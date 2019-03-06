//#137 Single Number II - https://leetcode.com/problems/single-number-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i <= 31; i++)
        {
            int count_bits = 0;
            for(auto num : nums)
            {
                if(num & (1 << i))
                    count_bits++;
            }
            if(count_bits % 3)
            {
                result |= (1 << i);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_num = {2, 2, 3, 2};
    int expected_answer = 3;
    assert(solution.singleNumber(given_num) == expected_answer);

    given_num = {0, 1, 0, 1, 0, 1, 99};
    expected_answer = 99;
    assert(solution.singleNumber(given_num) == expected_answer);

    given_num = {10};
    expected_answer = 10;
    assert(solution.singleNumber(given_num) == expected_answer);

    return 0;
}
