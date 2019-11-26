//#402 Remove K Digits - https://leetcode.com/problems/remove-k-digits/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for(auto& ch : num)
        {
            while(!result.empty() && k > 0 && result.back() > ch)
            {
                result.pop_back();
                k--;
            }
            if(!result.empty() || ch != '0')
                result.push_back(ch);
        }
        while(!result.empty() && k--)
            result.pop_back();
        return result.empty() ? "0" : result;
    }
};

int main()
{
    Solution solution;
    string given_num = "1234567890";
    int given_k = 9;
    string expected_answer = "0";
    assert(solution.removeKdigits(given_num, given_k) == expected_answer);

    given_num = "1432219";
    given_k = 3;
    expected_answer = "1219";
    assert(solution.removeKdigits(given_num, given_k) == expected_answer);

    return 0;
}
