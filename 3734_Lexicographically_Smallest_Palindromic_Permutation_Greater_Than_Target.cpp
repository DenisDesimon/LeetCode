//#3734 Lexicographically Smallest Palindromic Permutation Greater Than Target - https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        if(n == 1)
            return s > target ? s : "";
        int count[26] = {0};
        for(auto &letter : s)
            count[letter - 'a']++;
        string midChar = "";
        for(int i = 0; i < 26; i++)
        {
            if(count[i] % 2)
            {
                if(midChar != "")
                    return "";
                midChar = 'a' + i;
            }
            count[i] /= 2;
        }
        string left = "";
        auto check = [&](char cur){
            string palindrom = left + cur;
            for(int i = 25; i >= 0; i--)
                palindrom += string(count[i], 'a' + i);
            string right = palindrom;
            palindrom += midChar;
            reverse(right.begin(), right.end());
            palindrom += right;
            return palindrom > target;
        };

        for(int i = 0; i < n / 2; i++)
        {
            int j = 0;
            for(; j < 26; j++)
            {
                if(!count[j])
                    continue;
                count[j]--;
                if(check('a' + j))
                {
                    left += 'a' + j;
                    break;
                }
                count[j]++;
            }
            if(j == 26)
                return "";
            if(left[i] > target[i])
            {
                for(int j = 0; j < 26; j++)
                {
                    left += string(count[j], 'a' + j);
                }
                string right = left;
                left += midChar;
                reverse(right.begin(), right.end());
                return left + right;
            }
        }
        string right = left;
        left += midChar;
        reverse(right.begin(), right.end());
        return left + right;
    }
};


int main()
{
    Solution solution;
    string givenS = "baba";
    string givenTarget = "abba";
    string expectedAnswer = "baab";
    assert(solution.lexPalindromicPermutation(givenS, givenTarget) == expectedAnswer);

    givenS = "baba";
    givenTarget = "bbaa";
    expectedAnswer = "";
    assert(solution.lexPalindromicPermutation(givenS, givenTarget) == expectedAnswer);


    return 0;
}
