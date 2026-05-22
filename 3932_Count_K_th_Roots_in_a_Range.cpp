//#3932 Count K-th Roots in a Range - https://leetcode.com/problems/count-k-th-roots-in-a-range/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
    int fastPower(long long x, int power, int limit)
    {
        if(x == 0)
            return 0;
        long long result = 1;
        while(power)
        {
            if(power & 1)
            {
                if(result > limit / x)
                    return limit + 1;
                result *= x;
            }
            power >>= 1;
            if(power)
            {
                if(x > limit / x)
                    return limit + 1;
                x *= x;
            }
        }
        return result;
    }
    int findLower(int target, int k)
    {
        if(target == -1)
            return -1;
        long long left = 0, right = target, result = 0;
        while(left <= right)
        {
            long long mid = (right - left) / 2 + left;
            if(fastPower(mid, k, target) <= target)
            {
                result = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
public:
    int countKthRoots(int l, int r, int k) {
        int right = findLower(r, k);
        int left = findLower(l - 1, k);
        return right - left;
    }
};

int main()
{
    Solution solution;
    int givenL  = 1;
    int givenR  = 9;
    int givenK  = 3;
    int expectedAnswer = 2;
    assert(solution.countKthRoots(givenL, givenR, givenK) == expectedAnswer);

    givenL  = 8;
    givenR  = 30;
    givenK  = 2;
    expectedAnswer = 3;
    assert(solution.countKthRoots(givenL, givenR, givenK) == expectedAnswer);

    return 0;
}
