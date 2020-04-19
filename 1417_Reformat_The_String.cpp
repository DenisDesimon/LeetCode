//#1417 Reformat The String - https://leetcode.com/problems/reformat-the-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        string dig, symb;
        string result;
        for(auto& ch : s)
        {
            if(ch >= '0' && ch <= '9')
                dig.push_back(ch);
            else
                symb.push_back(ch);
        }
        if(abs((int)(dig.size() - symb.size())) > 1)
            return "";
        if(dig.size() > symb.size())
            swap(dig, symb);
        int i = 0;
        for(; i < (int)dig.size(); i++)
        {
            result.push_back(symb[i]);
            result.push_back(dig[i]);
        }
        if(i != (int)symb.size())
            result.push_back(symb.back());
        return result;
    }
};


int main()
{
    Solution solution;
    string given_s = "a0b1c2";
    string expected_answer = "a0b1c2";
    assert(solution.reformat(given_s) == expected_answer);

    given_s = "covid2019";
    expected_answer = "c2o0v1i9d";
    assert(solution.reformat(given_s) == expected_answer);

    return 0;
}
