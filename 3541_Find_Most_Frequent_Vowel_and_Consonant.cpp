//#3541 Find Most Frequent Vowel and Consonant  - https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int alphabet[26] = {0};
        for(auto &letter : s)
        {
            alphabet[letter - 'a']++;
        }
        int maxVowel = 0, maxConsonant = 0;
        for(int i = 0; i < 26; i++)
        {
            if(i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                maxVowel = max(maxVowel, alphabet[i]);
            else
                maxConsonant = max(maxConsonant, alphabet[i]);
        }
        return maxVowel + maxConsonant;
    }
};

int main()
{
    Solution solution;
    string givenS = "successes";
    int expectedAnswer = 6;
    assert(solution.maxFreqSum(givenS) == expectedAnswer);

    givenS = "aeiaeia";
    expectedAnswer = 3;
    assert(solution.maxFreqSum(givenS) == expectedAnswer);

    return 0;
}
