//#1513 Number of Substrings With Only 1s - https://leetcode.com/problems/number-of-substrings-with-only-1s/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        long long result = 0, length;
        int left = 0, mod = 1e9 + 7;
        for(int right = 0; right < (int)s.size(); right++)
        {
            if(s[right] == '0')
            {
                length = right - left;
                result += (length * (length  + 1) / 2) % mod;
                result %= mod;
                left = right + 1;
            }
        }
        length = s.size() - left;
        result += length * (length  + 1) / 2;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "0110111";
    int expectedAnswer = 9;
    assert(solution.numSub(givenS) == expectedAnswer);

    givenS = "111111";
    expectedAnswer = 21;
    assert(solution.numSub(givenS) == expectedAnswer);

    return 0;
}
