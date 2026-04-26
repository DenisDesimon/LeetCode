//#3913 Sort Vowels by Frequency - https://leetcode.com/problems/sort-vowels-by-frequency/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isVowel(char letter)
    {
        return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
    }
public:
    string sortVowels(string s) {
        int countFreq[26] = {0};
        int letterPos[26];
        fill(letterPos, letterPos + 25, -1);
        string sorted;
        int idx = 0;
        for(auto &letter : s)
        {
            if(letterPos[letter - 'a'] == -1)
                letterPos[letter - 'a'] = idx++;
            if(isVowel(letter))
            {
                countFreq[letter - 'a']++;
                sorted += letter;
            }
        }
        sort(sorted.begin(), sorted.end(), [&](char &left, char &right){if(countFreq[left - 'a'] == countFreq[right - 'a'])
                                                                            return letterPos[left - 'a'] < letterPos[right - 'a'];
                                                                        return countFreq[left - 'a'] > countFreq[right - 'a'];});
        string result;
        idx = 0;
        for(auto &letter : s)
        {
            if(isVowel(letter))
                result += sorted[idx++];
            else
                result += letter;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "leetcode";
    string expectedAnswer = "leetcedo";
    assert(solution.sortVowels(givenS) == expectedAnswer);

    givenS = "aeiaaioooa";
    expectedAnswer = "aaaaoooiie";
    assert(solution.sortVowels(givenS) == expectedAnswer);

    return 0;
}
