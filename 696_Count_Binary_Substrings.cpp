//#696 Count Binary Substrings - https://leetcode.com/problems/count-binary-substrings/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int countCur = 1, countPrev = 0, result = 0;
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(s[i] == s[i - 1])
                countCur++;
            else
            {
                result += min(countCur, countPrev);
                countPrev = countCur;
                countCur = 1;
            }
        }
        result += min(countCur, countPrev);
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "00110011";
    int expectedAnswer = 6;
    assert(solution.countBinarySubstrings(givenS) == expectedAnswer);

    givenS = "10101";
    expectedAnswer = 4;
    assert(solution.countBinarySubstrings(givenS) == expectedAnswer);

    return 0;
}
