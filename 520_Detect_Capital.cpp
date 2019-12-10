//#520 Detect Capital - https://leetcode.com/problems/detect-capital/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
       bool prev = word.back() >= 'a' && word.back() <= 'z';
       for(int i = word.size() - 2; i > 0; i--)
       {
           if(prev ^ (word[i] >= 'a' && word[i] <= 'z'))
               return false;
       }
       bool first = word.front() >= 'a' && word.front() <= 'z';
       return !(first ^ prev) || (!first && prev);
    }
};

int main()
{
    Solution solution;
    string given_word = "Leetcode";
    bool expected_answer = true;
    assert(solution.detectCapitalUse(given_word) == expected_answer);

    given_word = "USA";
    expected_answer = true;
    assert(solution.detectCapitalUse(given_word) == expected_answer);

    return 0;
}
