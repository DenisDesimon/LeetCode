//#150 Evaluate Reverse Polish Notation - https://leetcode.com/problems/evaluate-reverse-polish-notation/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> signs = {"+", "-", "*", "/"};
        stack<int> nums;
        for(auto token : tokens)
        {
            if(signs.count(token))
            {
                int right = nums.top();
                nums.pop();
                int left = nums.top();
                nums.pop();
                switch(token[0])
                {
                    case '+':
                        nums.push(left + right);
                        break;
                    case '-':
                        nums.push(left - right);
                        break;
                    case '*':
                        nums.push(left * right);
                        break;
                    case '/':
                        nums.push(left / right);
                        break;

                }
            }
            else
            {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};

int main()
{
    Solution solution;
    vector<string> given_tokens = {"2", "1", "+", "3", "*"};
    int expected_answer = 9;
    assert(solution.evalRPN(given_tokens) == expected_answer);

    given_tokens = {"4", "13", "5", "/", "+"};
    expected_answer = 6;
    assert(solution.evalRPN(given_tokens) == expected_answer);

    return 0;
}
