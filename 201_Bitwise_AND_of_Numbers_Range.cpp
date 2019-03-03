//#201 Bitwise AND of Numbers Range - https://leetcode.com/problems/bitwise-and-of-numbers-range/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
         int count = 0;
         while(n > m)
         {
             count++;
             m >>= 1, n >>= 1;
         }
         return m<<count;
    }
};

int main()
{
    Solution solution;
    int given_m = 5, given_n = 7;
    int expected_answer = 4;
    assert(solution.rangeBitwiseAnd(given_m, given_n) == expected_answer);

    given_m = 5, given_n = 5;
    expected_answer = 5;
    assert(solution.rangeBitwiseAnd(given_m, given_n) == expected_answer);

    given_m = 5, given_n = 8;
    expected_answer = 0;
    assert(solution.rangeBitwiseAnd(given_m, given_n) == expected_answer);

    return 0;
}
