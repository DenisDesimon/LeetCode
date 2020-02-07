//#1328 Break a Palindrome - https://leetcode.com/problems/break-a-palindrome/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1)
            return "";
        for(int i = 0; i < (int)palindrome.size(); i++)
        {
            if(palindrome[i] != 'a')
            {
                if(i == (int)palindrome.size() / 2 && (int)palindrome.size() % 2 == 1)
                    continue;
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome.back() = 'b';
        return palindrome;
    }
};

int main()
{
    Solution solution;
    string given_palindrome = "aba";
    string expected_answer = "abb";
    assert(solution.breakPalindrome(given_palindrome) == expected_answer);

    given_palindrome = "zzzz";
    expected_answer = "azzz";
    assert(solution.breakPalindrome(given_palindrome) == expected_answer);

    return 0;
}
