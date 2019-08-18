//#151 Reverse Words in a String - https://leetcode.com/problems/reverse-words-in-a-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result;
        if(s.empty())
            return result;
        int start = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == ' ')
            {
                if(i > 0 && s[i - 1] != ' ')
                {
                    result.insert(0, s.substr(start, i - start) + ' ');
                }
                start = i + 1;
            }
        }
        if(s.back() != ' ')
            result.insert(0, s.substr(start, s.size() - start) + ' ');
        if(!result.empty())
            result.pop_back();
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = " 1";
    string expected_answer = "1";
    assert(solution.reverseWords(given_s) == expected_answer);


    given_s = "the sky is blue";
    expected_answer = "blue is sky the";
    assert(solution.reverseWords(given_s) == expected_answer);

    return 0;
}
