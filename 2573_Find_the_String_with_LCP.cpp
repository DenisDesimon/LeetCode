//#2573 Find the String with LCP - https://leetcode.com/problems/find-the-string-with-lcp/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char cur = 'a';
        for(int i = 0; i < n; i++)
        {
            if(word[i] == '\0')
            {
                if(cur > 'z')
                    return "";
                word[i] = cur;
                for(int j = i + 1; j < n; j++)
                {
                    if(lcp[i][j] > 0)
                        word[j] = word[i];
                }
                cur++;
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(word[i] != word[j])
                {
                    if(lcp[i][j])
                        return "";
                }
                else
                {
                    if(i == n - 1 || j == n - 1)
                    {
                        if(lcp[i][j] != 1)
                            return "";
                    }
                    else
                    {
                        if(lcp[i][j] != lcp[i + 1][j + 1] + 1)
                            return "";
                    }
                }
            }
        }
        return word;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenLcp = {{4 ,0, 2, 0}, {0, 3, 0, 1}, {2, 0, 2, 0}, {0, 1, 0, 1}};
    string expectedAnswer = "abab";
    assert(solution.findTheString(givenLcp) == expectedAnswer);

    givenLcp = {{4, 3, 2, 1}, {3, 3, 2, 1}, {2, 2, 2, 1}, {1 ,1, 1, 3}};
    expectedAnswer = "";
    assert(solution.findTheString(givenLcp) == expectedAnswer);

    return 0;
}
