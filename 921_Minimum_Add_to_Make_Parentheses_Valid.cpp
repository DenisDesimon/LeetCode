//#921 Minimum Add to Make Parentheses Valid - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int result = 0;
        for(auto &parentheses : s)
        {
            if(parentheses == '(')
                count++;
            else
                count--;
            if(count < 0)
            {
                count = 0;
                result++;
            }
        }
        return result + count;
    }
};


int main()
{
    Solution solution;
    string givenS = "()))((";
    int expectedAnswer = 4;
    assert(solution.minAddToMakeValid(givenS) == expectedAnswer);

    givenS = "(((";
    expectedAnswer = 3;
    assert(solution.minAddToMakeValid(givenS) == expectedAnswer);

    return 0;
}
