//#316 Remove Duplicate Letters - https://leetcode.com/problems/remove-duplicate-letters/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        int letterCount[26] = {0};
        bool letterUsed[26] = {false};
        for(auto &letter : s)
            letterCount[letter - 'a']++;
        for(auto &letter : s)
        {
            if(!letterUsed[letter - 'a'])
            {
                while(!result.empty())
                {
                    char cur = result.back();
                    if(letterCount[cur - 'a'] && letter < cur)
                    {
                        result.pop_back();
                        letterUsed[cur - 'a'] = false;
                    }
                    else
                        break;
                }
                result.push_back(letter);
                letterUsed[letter - 'a'] = true;
            }
            letterCount[letter - 'a']--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "bcabc";
    string expectedAnswer = "abc";
    assert(solution.removeDuplicateLetters(givenS) == expectedAnswer);

    givenS = "cbacdcbc";
    expectedAnswer = "acdb";
    assert(solution.removeDuplicateLetters(givenS) == expectedAnswer);

    return 0;
}
