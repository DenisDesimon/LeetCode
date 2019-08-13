//#125 Valid Palindrome - https://leetcode.com/problems/valid-palindrome/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(right > left)
        {
            while(right > left && !((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= '0' && s[left] <= '9')))
                left++;
            while(right > left && !((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= '0' && s[right] <= '9')))
                right--;
            if(tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string given_s = "A man, a plan, a canal: Panama";
    bool expected_answer = true;
    assert(solution.isPalindrome(given_s) == expected_answer);

    given_s = "race a car";
    expected_answer = false;
    assert(solution.isPalindrome(given_s) == expected_answer);

    return 0;
}
