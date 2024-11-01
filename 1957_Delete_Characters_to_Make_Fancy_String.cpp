//#1957 Delete Characters to Make Fancy String - https://leetcode.com/problems/delete-characters-to-make-fancy-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result(1, s[0]);
        int count = 1;
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(s[i] != s[i - 1])
            {
                count = 0;
            }
            count++;
            if(count < 3)
                result += s[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "leeetcode";
    string expected_answer = "leetcode";
    assert(solution.makeFancyString(given_s) == expected_answer);

    given_s = "aaabaaaa";
    expected_answer = "aabaa";
    assert(solution.makeFancyString(given_s) == expected_answer);


    return 0;
}
