//#2472 Maximum Number of Non-overlapping Palindrome Substrings - https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        auto isPalindrom = [&] (int left, int right){
            while(left < right)
            {
                if(s[left++] != s[right--])
                    return false;
            }
            return true;
        };
        int result = 0, n = s.size(), start = 0;
        for(int right = k - 1; right < n; right++)
        {
            int left = right - k + 1;
            if(left >= start && isPalindrom(left, right))
            {
                result++;
                start = right + 1;
                continue;
            }
            left--;
            if(left >= start && isPalindrom(left, right))
            {
                result++;
                start = right + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "abaccdbbd";
    int givenK = 3;
    int expectedAnswer = 2;
    assert(solution.maxPalindromes(givenS, givenK) == expectedAnswer);

    givenS = "adbcda";
    givenK = 2;
    expectedAnswer = 0;
    assert(solution.maxPalindromes(givenS, givenK) == expectedAnswer);


    return 0;
}
