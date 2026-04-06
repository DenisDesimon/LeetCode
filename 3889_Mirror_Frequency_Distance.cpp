//#3889 Mirror Frequency Distance - https://leetcode.com/problems/mirror-frequency-distance/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int mirrorFrequency(string s) {
        int letters[26] = {0};
        int digits[10] = {0};
        for(auto &symb : s)
        {
            if(symb >= 'a' && symb <= 'z')
            {
                letters[symb - 'a']++;
            }
            else
                digits[symb - '0']++;
        }
        int result = 0;
        for(int i = 0; i < 26; i++)
        {
            if(letters[i] || letters[25 - i])
            {
                result += abs(letters[i] - letters[25 - i]);
                letters[25 - i] = 0;
                letters[i] = 0;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            if(digits[i] || digits[9 - i])
            {
                result += abs(digits[i] - digits[9 - i]);
                digits[9 - i] = 0;
                digits[i] = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "ab1z9";
    int expectedAnswer = 3;
    assert(solution.mirrorFrequency(givenS) == expectedAnswer);

    givenS = "4m7n";
    expectedAnswer = 2;
    assert(solution.mirrorFrequency(givenS) == expectedAnswer);

    return 0;
}
