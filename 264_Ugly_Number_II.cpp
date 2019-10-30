//#264 Ugly Number II - https://leetcode.com/problems/ugly-number-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> ugly_nums(n);
        ugly_nums[0] = 1;
        int first = 0, second = 0, third = 0;
        for(int i = 1; i < n; i++)
        {
            ugly_nums[i] = min({ugly_nums[first] * 2, ugly_nums[second] * 3, ugly_nums[third] * 5});
            if(ugly_nums[i] == ugly_nums[first] * 2)
                first++;
            if(ugly_nums[i] == ugly_nums[second] * 3)
                second++;
            if(ugly_nums[i] == ugly_nums[third] * 5)
                third++;
        }
        return ugly_nums[n - 1];
    }
};

int main()
{
    Solution solution;
    int given_n = 10;
    int expected_answer = 12;
    assert(solution.nthUglyNumber(given_n) == expected_answer);

    given_n = 32;
    expected_answer = 90;
    assert(solution.nthUglyNumber(given_n) == expected_answer);

    return 0;
}
