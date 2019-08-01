//#69 Sqrt(x) - https://leetcode.com/problems/sqrtx/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long left = -1, num = x, right = num + 1;
        while(right - left > 1)
        {
            long long mid = (left + right) / 2;
            if(mid * mid <= num)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
    Solution solution;
    int given_x = 8;
    int expected_answer = 2;
    assert(solution.mySqrt(given_x) == expected_answer);

    given_x = INT_MAX;
    expected_answer = 46340;
    assert(solution.mySqrt(given_x) == expected_answer);

    return 0;
}
