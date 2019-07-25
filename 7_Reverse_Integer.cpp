//#7 Reverse Integer - https://leetcode.com/problems/reverse-integer/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0)
        {
            int digit = x % 10;
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
                return 0;
            if(result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8))
                return 0;
            result = result * 10 + digit;
            x /= 10;

        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_x = -2147483412;
    int expected_answer = -2143847412;
    assert(solution.reverse(given_x) == expected_answer);

    given_x = 2133;
    expected_answer = 3312;
    assert(solution.reverse(given_x) == expected_answer);

    return 0;
}
