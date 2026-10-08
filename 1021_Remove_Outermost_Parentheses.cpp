//#1021 Remove Outermost Parentheses - https://leetcode.com/problems/remove-outermost-parentheses/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string result;
        int n = s.size();
        int last = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;
            else
                count--;
            if(!count)
            {
                result += s.substr(last + 1, i - last - 1);
                last = i + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenEvents  = "(()())(())";
    string expectedAnswer = "()()()";
    assert(solution.removeOuterParentheses(givenEvents) == expectedAnswer);

    givenEvents = "(()())(())(()(()))";
    expectedAnswer = "()()()()(())";
    assert(solution.removeOuterParentheses(givenEvents) == expectedAnswer);

    return 0;
}
