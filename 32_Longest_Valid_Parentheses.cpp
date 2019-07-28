//#32 Longest Valid Parentheses - https://leetcode.com/problems/longest-valid-parentheses/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parentheses;
        int result = 0;
        parentheses.push(-1);
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '(')
                parentheses.push(i);
            else
            {
                parentheses.pop();
                if(parentheses.empty())
                    parentheses.push(i);
                else
                    result = max(result, i - parentheses.top());
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "(()";
    int expected_answer = 2;
    assert(solution.longestValidParentheses(given_s) == expected_answer);

    given_s = "()(()";
    expected_answer = 2;
    assert(solution.longestValidParentheses(given_s) == expected_answer);

    given_s = ")(((((()())()()))()(()))(";
    expected_answer = 22;
    assert(solution.longestValidParentheses(given_s) == expected_answer);

    return 0;
}
