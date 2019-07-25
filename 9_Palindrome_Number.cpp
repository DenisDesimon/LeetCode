//#9 Palindrome Number - https://leetcode.com/problems/palindrome-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reversed = 0;
        while(x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return x == reversed || x == reversed / 10;
    }
};

int main()
{
    Solution solution;
    int given_x = 121;
    bool expected_answer = true;
    assert(solution.isPalindrome(given_x) == expected_answer);

    given_x = -121;
    expected_answer = false;
    assert(solution.isPalindrome(given_x) == expected_answer);


    return 0;
}
