//#1003 Check If Word Is Valid After Substitutions - https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValid(string S) {
        stack<char> hash;
        for(auto ch : S)
        {
           if(ch < 'c')
               hash.push(ch);
           else
           {
               if(!hash.empty() && hash.top() == 'b')
               {
                   hash.pop();
                   if(!hash.empty() && hash.top() == 'a')
                       hash.pop();
                   else
                       return false;
               }
               else
                   return false;
           }
        }
        return hash.empty();
    }
};

int main()
{
    Solution solution;
    string given_string = {"abcabcababcc"};
    bool  expected_answer = true;
    assert(solution.isValid(given_string) == expected_answer);


    given_string = {"abccba"};
    expected_answer = false;
    assert(solution.isValid(given_string) == expected_answer);

    return 0;
}
