//#3713 Longest Balanced Substring I - https://leetcode.com/problems/longest-balanced-substring-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int letters[26] = {0};
            for(int j = i; j < n; j++)
            {
                letters[s[j] - 'a']++;
                if(j - i + 1 > result)
                {
                    int prev = -1;
                    int k = 0;
                    for(; k < 26; k++)
                    {
                        if(letters[k] == 0)
                            continue;
                        if(prev == -1)
                            prev = letters[k];
                        else if(prev != letters[k])
                            break;
                    }
                    if(k == 26)
                        result = j - i + 1;
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    string givenS = "abbac";
    int expectedAnswer = 4;
    assert(solution.longestBalanced(givenS) == expectedAnswer);

    givenS = "zzabccy";
    expectedAnswer = 4;
    assert(solution.longestBalanced(givenS) == expectedAnswer);

    return 0;
}
