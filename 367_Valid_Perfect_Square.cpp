//#367 Valid Perfect Square - https://leetcode.com/problems/valid-perfect-square/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0)
            return 0;
        long long left = 0;
        long long right = (long long)num + 1;
        while(right - left > 1)
        {
            long long mid = left + (right - left) / 2;
            if(mid * mid > num)
                right = mid;
            else
                left = mid;
        }
        return left * left == num;
    }
};

int main()
{
    Solution solution;
    int given_num = 81;
    bool expected_answer = true;
    assert(solution.isPerfectSquare(given_num) == expected_answer);

    given_num = INT_MAX;
    expected_answer = false;
    assert(solution.isPerfectSquare(given_num) == expected_answer);

    return 0;
}
