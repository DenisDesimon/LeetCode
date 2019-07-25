//#8 String to Integer (atoi) - https://leetcode.com/problems/string-to-integer-atoi/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int sign = 1;
        bool reading_nums = false;
        for(int i = 0; i < (int)str.size(); i++)
        {
            if(str[i] == ' ' && !reading_nums)
                continue;
            else if(str[i] == '-' && !reading_nums)
            {
                sign = -1;
                reading_nums = true;
                continue;
            }
            else if(str[i] == '+' && !reading_nums)
            {
                sign = 1;
                reading_nums = true;
                continue;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                if(result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - 48) > 7))
                    return INT_MAX;
                if(result < INT_MIN / 10 || (result == INT_MIN / 10 && (str[i] - 48) > 8))
                    return INT_MIN;
                if(sign == -1)
                {
                    result = result * 10 - (str[i] - 48);
                }
                else
                    result = result * 10 + (str[i] - 48);
                reading_nums = true;
                continue;
            }
            break;
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string given_str = "-2147483649";
    int expected_answer = -2147483648;
    assert(solution.myAtoi(given_str) == expected_answer);

    given_str = "4193 with words";
    expected_answer = 4193;
    assert(solution.myAtoi(given_str) == expected_answer);

    return 0;
}
