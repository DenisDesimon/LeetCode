//#3121 Count the Number of Special Characters II - https://leetcode.com/problems/count-the-number-of-special-characters-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lowerLast(26, n);
        vector<int> upperFirst(26, -1);
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
                lowerLast[word[i] - 'a'] = i;
            else if(upperFirst[word[i] - 'A'] == -1)
                upperFirst[word[i] - 'A'] = i;
        }
        for(int i = 0; i < 26; i++)
        {
            if(lowerLast[i] < upperFirst[i])
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenWord = "aaAbcBC";
    int expectedAnswer = 3;
    assert(solution.numberOfSpecialChars(givenWord) == expectedAnswer);

    givenWord  = "abc";
    expectedAnswer = 0;
    assert(solution.numberOfSpecialChars(givenWord) == expectedAnswer);

    return 0;
}
