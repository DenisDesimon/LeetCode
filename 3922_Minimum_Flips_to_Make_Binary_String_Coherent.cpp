//#3922 Minimum Flips to Make Binary String Coherent - https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n < 3)
            return 0;
        if(n == 3)
            return s == "011" || s == "110" ? 1 : 0;
        int countOnes = 0;
        for(auto &letter : s)
        {
            countOnes += letter - '0';
        }
        if(s[0] == '1' && s[n - 1] == '1')
            return  min(n - countOnes, max(0, countOnes - 2));
        return min(n - countOnes, max(0, countOnes - 1));
    }
};

int main()
{
    Solution solution;
    string givenS  = "1010";
    int expectedAnswer = 1;
    assert(solution.minFlips(givenS) == expectedAnswer);

    givenS = "0110";
    expectedAnswer = 1;
    assert(solution.minFlips(givenS) == expectedAnswer);

    return 0;
}
