//#3120 Count the Number of Special Characters I - https://leetcode.com/problems/count-the-number-of-special-characters-i/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false};
        bool upper[26] = {false};
        for(auto &letter : word)
        {
            if(letter >= 'a' && letter <= 'z')
                lower[letter - 'a'] = true;
            else
                upper[letter - 'A'] = true;
        }
        int count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(lower[i] && upper[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution solution;
    string givenWord = "aaAbcBC";
    int expectedAnswer = 3;
    assert(solution.numberOfSpecialChars(givenWord) == expectedAnswer);

    givenWord  = "abc";
    expectedAnswer = 0;
    assert(solution.numberOfSpecialChars(givenWord) == expectedAnswer);

    return 0;
}
