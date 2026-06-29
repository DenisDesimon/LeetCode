//#1967 Number of Strings That Appear as Substrings in Word - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int result = 0;
        int n = word.size();
        for(auto &pattern : patterns)
        {
            int m = pattern.size();
            for(int i = 0; i < n; i++)
            {
                int j = 0;
                for(; j < m; j++)
                {
                    if(pattern[j] != word[i + j])
                        break;
                }
                if(j == m)
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenPatterns = {"a", "abc", "bc", "d"};
    string givenWord = "abc";
    int expectedAnswer = 3;
    assert(solution.numOfStrings(givenPatterns, givenWord) == expectedAnswer);

    givenPatterns = {"a", "a", "a"};
    givenWord = "ab";
    expectedAnswer = 3;
    assert(solution.numOfStrings(givenPatterns, givenWord) == expectedAnswer);

    return 0;
}
