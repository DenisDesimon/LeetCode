//#1925 Count Square Sum Triples - https://leetcode.com/problems/count-square-sum-triples/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
    int gcd(int left, int right)
    {
        while(right)
        {
            int temp = right;
            right = left % right;
            left = temp;
        }
        return left;
    }
public:
    int countTriples(int lim) {
        int result = 0;
        for(int m = 2; m * m < lim; m++)
        {
            for(int n = 1; n < m; n++)
            {
                if(gcd(m, n) != 1 || ~(m - n) & 1)
                    continue;
                int c = m * m + n * n;
                if(c > lim)
                    continue;
                result += (lim / c) << 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenLim = 5;
    int expectedAnswer = 2;
    assert(solution.countTriples(givenLim) == expectedAnswer);

    givenLim = 10;
    expectedAnswer = 4;
    assert(solution.countTriples(givenLim) == expectedAnswer);

    return 0;
}
