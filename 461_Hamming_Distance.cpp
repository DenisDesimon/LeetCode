//#461 Hamming Distance - https://leetcode.com/problems/hamming-distance/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        x ^= y;
        for(int i = 31; i >= 0; i--)
        {
            if(x & (1 << i))
                result++;
        }
        return result;
    }

    int hammingDistance_builtin(int x, int y) {
            return __builtin_popcount(x ^ y);
        }
};

int main()
{
    Solution solution;
    int given_x = 1, given_y = 4;
    int expected_answer = 2;
    assert(solution.hammingDistance(given_x, given_y) == expected_answer);
    assert(solution.hammingDistance_builtin(given_x, given_y) == expected_answer);

    given_x = 127;
    given_y = 128;
    expected_answer = 8;
    assert(solution.hammingDistance(given_x, given_y) == expected_answer);
    assert(solution.hammingDistance_builtin(given_x, given_y) == expected_answer);

    return 0;
}
