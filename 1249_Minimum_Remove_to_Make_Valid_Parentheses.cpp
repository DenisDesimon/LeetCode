//#1249 Minimum Remove to Make Valid Parentheses - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                if(st.empty())
                {
                    s.erase(s.begin() + i);
                    i--;
                }
                else
                    st.pop();
            }
        }
        while(!st.empty())
        {
            s.erase(s.begin() + st.top());
            st.pop();
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string given_s = "lee(t(c)o)de)";
    string expected_answer = "lee(t(c)o)de";
    assert(solution.minRemoveToMakeValid(given_s) == expected_answer);

    given_s = "))((";
    expected_answer = "";
    assert(solution.minRemoveToMakeValid(given_s) == expected_answer);

    return 0;
}
