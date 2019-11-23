//#394 Decode String - https://leetcode.com/problems/decode-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int index = 0;
    string decodeString(string s) {
        string result = "";
        while(index != (int)s.size() && s[index] != ']')
        {
            if(!(s[index] > '0' && s[index] < '9'))
                result += s[index];
            else
            {
                int count = 0;
                while(s[index] != '[')
                    count = count * 10 + (s[index++] - '0');
                index++;
                string sub_res = decodeString(s);
                while(count--)
                    result += sub_res;
            }
            index++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "3[a]2[bc]";
    string expected_answer = "aaabcbc";
    assert(solution.decodeString(given_s) == expected_answer);

    solution.index = 0;
    given_s = "3[a2[bc]]";
    expected_answer = "abcbcabcbcabcbc";
    assert(solution.decodeString(given_s) == expected_answer);

    return 0;
}
