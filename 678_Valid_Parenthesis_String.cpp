//#678 Valid Parenthesis String - https://leetcode.com/problems/valid-parenthesis-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int count_left = 0, count_sum = 0;
        for(auto& ch : s)
        {
            count_left += ch == '(' ? 1 : -1;
            count_sum += ch != ')' ? 1 : -1;
            if(count_sum < 0)
                return false;
            count_left = max(count_left, 0);
        }
        return !count_left;
    }
};

int main()
{
    Solution solution;
    string given_s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()";
    bool expected_answer = false;
    assert(solution.checkValidString(given_s) == expected_answer);

    given_s = "(*))";
    expected_answer = true;
    assert(solution.checkValidString(given_s) == expected_answer);

    return 0;
}
