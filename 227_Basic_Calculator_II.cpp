//#227 Basic Calculator II - https://leetcode.com/problems/basic-calculator-ii/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        int num = 0, result = 0;
        char sign = '+';
        s += '+';
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            if(s[i] >= '0' && s[i] <= '9')
            {
                num *= 10;
                num += (int)s[i] - 48;
            }
            else
            {
                if(sign == '+')
                    nums.push(num);
                else if(sign == '-')
                    nums.push(-num);
                else if(sign == '*')
                {
                    num *= nums.top();
                    nums.pop();
                    nums.push(num);
                }
                else
                {
                    num = nums.top() / num;
                    nums.pop();
                    nums.push(num);
                }
                sign = s[i];
                num = 0;
            }
        }
        while(!nums.empty())
        {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "3+2*2";
    int expected_answer = 7;
    assert(solution.calculate(given_s) == expected_answer);

    given_s = " 3+5 / 2 ";
    expected_answer = 5;
    assert(solution.calculate(given_s) == expected_answer);


    return 0;
}
