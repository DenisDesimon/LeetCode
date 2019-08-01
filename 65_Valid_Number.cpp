//#65 Valid Number - https://leetcode.com/problems/valid-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool point = false;
        bool exp = false;
        bool num_start = false;
        bool gap = false;
        int s_size = s.size();
        for(int i = 0; i < s_size; i++)
        {
            if(s[i] == ' ')
            {
                if(num_start)
                    gap = true;
                continue;
            }
            if((s[i] == '+' || s[i] == '-') && !gap && i + 1 < s_size && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '.') && (!num_start || (i != 0 && s[i - 1] == 'e')))
            {
                num_start = true;
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9' && !gap)
            {
                num_start = true;
                continue;
            }
            if(s[i] == '.' && !exp && !point && !gap && ((i != 0 && s[i - 1] >= '0' && s[i - 1] <= '9') || (i + 1 < s_size && s[i + 1] >= '0' && s[i + 1] <= '9')))
            {
                point = true;
                num_start = true;
                continue;
            }
            if(s[i] == 'e' && !exp && !gap && (i != 0 && ((s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == '.')) && (i + 1 < s_size && ((s[i + 1] >= '0' && s[i + 1] <= '9') || s[i + 1] == '+' || s[i + 1] == '-')))
            {
                exp = true;
                continue;
            }
            else
                return false;
        }
        return num_start;
    }
};

int main()
{
    Solution solution;
    string given_s = " -54.53061";
    bool expected_answer = true;
    assert(solution.isNumber(given_s) == expected_answer);

    given_s = " 005047e+6";
    expected_answer = true;
    assert(solution.isNumber(given_s) == expected_answer);

    return 0;
}
