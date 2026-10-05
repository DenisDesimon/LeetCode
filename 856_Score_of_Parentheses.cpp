//#856 Score of Parentheses - https://leetcode.com/problems/score-of-parentheses/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        if(n == 2)
            return 1;
        int count = 0;
        int result = 0;
        int left = n - 1, right = n - 1;
        while(left >= 0)
        {
            if(s[left] == ')')
                count++;
            else
                count--;
            if(count == 0)
            {
                if(left == 0 && right == n - 1)
                    return scoreOfParentheses(s.substr(1, n - 2)) * 2;
                result += scoreOfParentheses(s.substr(left, right - left + 1));
                right = left - 1;
            }
            left--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "()()()()()()()(((())))";
    int expectedAnswer = 15;
    assert(solution.scoreOfParentheses(givenS) == expectedAnswer);

    givenS = "(((((((((()()()))))((((())))))(((((((())))))))))))";
    expectedAnswer = 4096;
    assert(solution.scoreOfParentheses(givenS) == expectedAnswer);

    return 0;
}
