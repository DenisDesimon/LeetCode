//#1935 Maximum Number of Words You Can Type  - https://leetcode.com/problems/maximum-number-of-words-you-can-type/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters){
        bool brokenLett[26] = {false};
        for(auto &letter : brokenLetters)
            brokenLett[letter - 'a'] = true;;
        int result = 0;
        bool flag = true;
        for(auto &letter : text)
        {
            if(letter == ' ')
            {
                result += flag;
                flag = true;
                continue;
            }
            if(brokenLett[letter - 'a'])
                flag = false;
        }
        result += flag;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenText  = "hello world";
    string givenBrokenLetters = "ad";
    int expectedAnswer = 1;
    assert(solution.canBeTypedWords(givenText, givenBrokenLetters) == expectedAnswer);

    givenText = "leet code";
    givenBrokenLetters = "e";
    expectedAnswer = 0;
    assert(solution.canBeTypedWords(givenText, givenBrokenLetters) == expectedAnswer);

    return 0;
}
