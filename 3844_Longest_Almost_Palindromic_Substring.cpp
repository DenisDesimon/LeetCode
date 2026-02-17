//#3844 Longest Almost-Palindromic Substring - https://leetcode.com/problems/longest-almost-palindromic-substring/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int almostPalindromic(string s) {
        int result = 0;
        int n = s.size();
        auto expand = [&](int left, int right)
        {
            while(left >= 0 && right < n && s[left] == s[right])
            {
                left--, right++;
            }
            result = max(result, right - left - 1);
            return make_pair(left, right);
        };
        for(int i = 0; i < 2 * n - 1; i++)
        {
            pair<int, int> borders = expand(i / 2, (i + 1)/ 2);
            expand(borders.first, borders.second + 1);
            expand(borders.first - 1, borders.second);
        }
        return min(result, n);
    }
};

int main()
{
    Solution solution;
    string givenS = "abba";
    int expectedAnswer = 4;
    assert(solution.almostPalindromic(givenS) == expectedAnswer);

    givenS = "abbab";
    expectedAnswer = 5;
    assert(solution.almostPalindromic(givenS) == expectedAnswer);

    return 0;
}
