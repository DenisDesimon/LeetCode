//#3518 Smallest Palindromic Rearrangement II - https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    long long combCount(int n, int m, int k)
    {
        long long result = 1;
        m = min(m, n - m);
        for(long long i = 1; i <= m; i++)
        {
            result = result * (n - i + 1) / i;
            if(result > k)
                return k + 1;
        }
        return result;
    }
public:
    string smallestPalindrome(string s, int k) {
        int half = s.size() / 2;
        int freq[26] = {0};
        for(int i = 0; i < half; i++)
            freq[s[i] - 'a']++;
        auto permutations = [&](int rem){
            long long ways = 1;
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] == 0)
                    continue;
                ways *= combCount(rem, freq[i], k);
                if(ways > k)
                    break;
                rem -= freq[i];
            }
            return ways;
        };

        string left = "";
        long long waysCount = 1;

        for(int pos = 0; pos < half; pos++)
        {
            for(int i = 0; i < 26; i++)
            {
                if(freq[i] == 0)
                    continue;
                freq[i]--;

                long long ways = permutations(half - pos - 1);
                if(waysCount + ways > k)
                {
                    left += char(i + 'a');
                    break;
                }
                freq[i]++;
                waysCount += ways;
            }
        }
        if((int)left.size() < half)
            return "";
        string mid = s.size() % 2 ? string(1, s[half]) : "";
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};

int main()
{
    Solution solution;
    string givenS = "abba";
    int givenK = 2;
    string expectedAnswer = "baab";
    assert(solution.smallestPalindrome(givenS, givenK) == expectedAnswer);

    givenS = "bacab";
    givenK = 1;
    expectedAnswer = "abcba";
    assert(solution.smallestPalindrome(givenS, givenK) == expectedAnswer);

    return 0;
}
