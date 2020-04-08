//#1405 Longest Happy String - https://leetcode.com/problems/longest-happy-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c, char first = 'a', char second = 'b', char third = 'c') {
        if(b > a)
            return longestDiverseString(b, a, c, second, first, third);
        else if(c > b)
            return longestDiverseString(a, c, b, first, third, second);
        else if(b == 0)
            return string(min(2, a), first);
        int count_a = min(2, a), count_b = a - count_a >= b ? 1 : 0;
        return string(count_a, first) + string(count_b, second) + longestDiverseString(a - count_a, b - count_b, c, first, second, third);
    }
};

int main()
{
    Solution solution;
    int given_a = 1, given_b = 1, given_c = 7;
    string expected_answer = "ccaccbcc";
    assert(solution.longestDiverseString(given_a, given_b, given_c) == expected_answer);

    given_a = 2, given_b = 2, given_c = 1;
    expected_answer = "aabbc";
    assert(solution.longestDiverseString(given_a, given_b, given_c) == expected_answer);

    return 0;
}
