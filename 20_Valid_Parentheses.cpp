//#20 Valid Parentheses - https://leetcode.com/problems/valid-parentheses/
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> count;
        for(int i = 0; i < (int)s.size(); i++)
        {
            switch(s[i])
            {
                case '(':
                    count.push(s[i]);
                    break;
                case ')':
                    if(count.empty() || count.top() != '(')
                        return false;
                    count.pop();
                    break;
                case '{':
                    count.push(s[i]);
                    break;
                case '}':
                    if(count.empty() || count.top() != '{')
                        return false;
                    count.pop();
                    break;
                case '[':
                    count.push(s[i]);
                    break;
                case ']':
                    if(count.empty() || count.top() != '[')
                        return false;
                    count.pop();
                    break;
            }
        }
        return count.empty();
    }
};

int main()
{
    Solution solution;
    string given_s = "([)]";
    bool expected_answer = false;
    assert(solution.isValid(given_s) == expected_answer);

    given_s = "([{}])";
    expected_answer = true;
    assert(solution.isValid(given_s) == expected_answer);

    return 0;
}
