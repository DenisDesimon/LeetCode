//#1967 Number of Strings That Appear as Substrings in Word - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string, int> countPatterns;
        for(auto &pattern : patterns)
        {
            countPatterns[pattern]++;
        }
        int n = word.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            string cur = "";
            for(int j = i; j < n; j++)
            {
                cur += word[j];
                if(countPatterns.count(cur))
                {
                    result += countPatterns[cur];
                    countPatterns.erase(cur);
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
