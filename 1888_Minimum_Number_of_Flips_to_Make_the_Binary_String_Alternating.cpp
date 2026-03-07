//#1888 Minimum Number of Flips to Make the Binary String Alternating - https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            count += s[i] - '0' == (i % 2);
        }
        int result = min(count, n - count);
        for(int i = 0; i < n - 1; i++)
        {
            count -= s[i] - '0' == (i % 2);
            count += s[i] - '0' == ((n + i) % 2);
            result = min(result, min(count, n - count));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "111000";
    int expectedAnswer = 2;
    assert(solution.minFlips(givenS) == expectedAnswer);

    givenS = "1110";
    expectedAnswer = 1;
    assert(solution.minFlips(givenS) == expectedAnswer);

    return 0;
}
