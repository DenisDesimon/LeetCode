//#3612 Process String with Special Operations I - https://leetcode.com/problems/process-string-with-special-operations-i/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result;
        for(auto &letter : s)
        {
            if(letter >= 'a' && letter <= 'z')
            {
                result += letter;
            }
            else if(letter == '*' && !result.empty())
                result.pop_back();
            else if(letter == '#')
                result += result;
            else
                reverse(result.begin(), result.end());
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "a#b%*";
    string expectedAnswer = "ba";
    assert(solution.processStr(givenS) == expectedAnswer);

    givenS = "z*#";
    expectedAnswer = "";
    assert(solution.processStr(givenS) == expectedAnswer);

    return 0;
}
