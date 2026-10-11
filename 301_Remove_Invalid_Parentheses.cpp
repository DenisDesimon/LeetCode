//#301 Remove Invalid Parentheses  - https://leetcode.com/problems/remove-invalid-parentheses/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    void forward(string s, int countStart, int parenStart, vector<string> &result)
    {
        int count = 0;
        int n = s.size();
        for(int i = countStart; i < n; i++)
        {
            count += (s[i] == '(') - (s[i] == ')');
            if(count >= 0)
                continue;
            for(int j = parenStart; j <= i; j++)
            {
                if(s[j] == ')' && (j == parenStart || s[j - 1] != ')'))
                    forward(s.substr(0, j) + s.substr(j + 1), i, j, result);
            }
            return;
        }
        backward(s, n - 1, n - 1, result);
    }
    void backward(string s, int countStart, int parenStart, vector<string> &result)
    {
        int count = 0;
        int n = s.size();
        for(int i = countStart; i >= 0; i--)
        {
            count += (s[i] == ')') - (s[i] == '(');
            if(count >= 0)
                continue;
            for(int j = parenStart; j >= i; j--)
            {
                if(s[j] == '(' && (j == parenStart || s[j + 1] != '('))
                    backward(s.substr(0, j) + s.substr(j + 1), i - 1, j - 1, result);
            }
            return;
        }
        result.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        forward(s, 0, 0, result);
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS  = "()())()";
    vector<string> expectedAnswer = {"(())()", "()()()"};
    assert(solution.removeInvalidParentheses(givenS) == expectedAnswer);

    givenS = "(a)())()";
    expectedAnswer = {"(a())()", "(a)()()"};
    assert(solution.removeInvalidParentheses(givenS) == expectedAnswer);

    return 0;
}
