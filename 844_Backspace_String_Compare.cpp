//#844 Backspace String Compare - https://leetcode.com/problems/backspace-string-compare/
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stack_S, stack_T;
        for(auto& ch : S)
        {
            if(ch == '#')
            {
                if(!stack_S.empty())
                    stack_S.pop();
            }
            else
                stack_S.push(ch);
        }
        for(auto& ch : T)
        {
            if(ch == '#')
            {
                if(!stack_T.empty())
                    stack_T.pop();
            }
            else
                stack_T.push(ch);
        }
        while(!stack_S.empty() && !stack_T.empty())
        {
            if(stack_S.top() != stack_T.top())
                return false;
            stack_S.pop(), stack_T.pop();
        }
        return stack_S.empty() && stack_T.empty();
    }
};


int main()
{
    Solution solution;
    string given_S = "bxj##tw";
    string given_T = "bxj###tw";
    bool expected_answer = false;
    assert(solution.backspaceCompare(given_S, given_T) == expected_answer);

    given_S = "a##c";
    given_T = "#a#c";
    expected_answer = true;
    assert(solution.backspaceCompare(given_S, given_T) == expected_answer);

    return 0;
}
