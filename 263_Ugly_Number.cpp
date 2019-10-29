//#263 Ugly Number - https://leetcode.com/problems/ugly-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
            return false;
        vector<int> nums = {2, 3, 5};
        for(auto div : nums)
        {
            while(num % div == 0)
                num /= div;
        }
        return num == 1;
    }
};

int main()
{
    Solution solution;
    int given_num = 6;
    bool expected_answer = true;
    assert(solution.isUgly(given_num) == expected_answer);

    given_num = 14;
    expected_answer = false;
    assert(solution.isUgly(given_num) == expected_answer);

    return 0;
}
