//#172 Factorial Trailing Zeroes - https://leetcode.com/problems/factorial-trailing-zeroes/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        for(long long mult = 5; mult <= n; mult *= 5)
        {
            result += n / mult;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 12;
    int expected_answer = 2;
    assert(solution.trailingZeroes(given_n) == expected_answer);

    given_n = 56;
    expected_answer = 13;
    assert(solution.trailingZeroes(given_n) == expected_answer);

    return 0;
}
