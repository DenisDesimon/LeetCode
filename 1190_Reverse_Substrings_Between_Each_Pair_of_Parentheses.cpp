//#1190 Reverse Substrings Between Each Pair of Parentheses - https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> parenthesesIdx;
        vector<int> idxBorder(n);
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                parenthesesIdx.push(i);
            else if(s[i] == ')')
            {
                int left = parenthesesIdx.top();
                parenthesesIdx.pop();
                idxBorder[left] = i;
                idxBorder[i] = left;
            }
        }
        string result;
        for(int i = 0, dir = 1; i < n; i += dir)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                dir = -dir;
                i = idxBorder[i];
                continue;
            }
            result += s[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "(abcd)";
    string expectedAnswer = "dcba";
    assert(solution.reverseParentheses(givenS) == expectedAnswer);

    givenS = "(u(love)i)";
    expectedAnswer = "iloveu";
    assert(solution.reverseParentheses(givenS) == expectedAnswer);


    return 0;
}
