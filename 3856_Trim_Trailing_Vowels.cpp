//#3856 Trim Trailing Vowels - https://leetcode.com/problems/trim-trailing-vowels/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string trimTrailingVowels(string s) {
        for(int i = s.size() - 1; i >= 0; )
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                i--;
            else
                return s.substr(0, i + 1);
        }
        return "";
    }
};

int main()
{
    Solution solution;
    string givenS = "idea";
    string expectedAnswer = "id";
    assert(solution.trimTrailingVowels(givenS) == expectedAnswer);

    givenS = "aeiou";
    expectedAnswer = "";
    assert(solution.trimTrailingVowels(givenS) == expectedAnswer);

    return 0;
}
