//#22 Generate Parentheses - https://leetcode.com/problems/generate-parentheses/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1)
            return {"()"};
        else if(n == 0)
            return {""};
        vector<string> result;
        for(int i = 0; i < n; i++)
        {
            auto left_parenth = generateParenthesis(i);
            auto center_parenth = generateParenthesis(n - i - 1);
            for(auto left : left_parenth)
            {
                for(auto center: center_parenth)
                {
                    result.push_back(left + '(' + center + ')');
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    vector<string> expected_answer = {"((()))", "(()())", "()(())", "(())()", "()()()"};
    assert(solution.generateParenthesis(given_n) == expected_answer);

    given_n = 2;
    expected_answer = {"(())", "()()"};
    assert(solution.generateParenthesis(given_n) == expected_answer);

    return 0;
}
