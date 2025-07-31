//#3136 Valid Word - https://leetcode.com/problems/valid-word/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;
        bool hasVowel = false;
        bool hasConsonant = false;
        for(auto &letter: word)
        {
            letter = tolower(letter);
            if(letter >= 'a' && letter <= 'z')
            {
                if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
            else if(letter < '0' || letter > '9')
                return false;
        }
        return hasConsonant && hasVowel;
    }
};

int main()
{
    Solution solution;

    string givenWord = "234Adas";
    bool expectedAnswer = true;
    assert(solution.isValid(givenWord) == expectedAnswer);

    givenWord = "a3$e";
    expectedAnswer = false;
    assert(solution.isValid(givenWord) == expectedAnswer);

    return 0;
}
