//#2785 Sort Vowels in a String  - https://leetcode.com/problems/sort-vowels-in-a-string/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<int> indexes;
        string vowels;
        for(int i = 0; i < (int)s.size(); i++)
        {
            char lowerS = tolower(s[i]);
            if(lowerS == 'a' || lowerS == 'e' || lowerS == 'i' || lowerS == 'o' || lowerS == 'u')
            {
                vowels += s[i];
                indexes.push_back(i);
            }
        }
        sort(vowels.begin(), vowels.end());
        int vowelIdx = 0;
        for(auto &index : indexes)
            s[index] = vowels[vowelIdx++];
        return s;
    }
};


int main()
{
    Solution solution;
    string givenS = "lEetcOde";
    string expectedAnswer = "lEOtcede";
    assert(solution.sortVowels(givenS) == expectedAnswer);

    givenS = "lYmpH";
    expectedAnswer = "lYmpH";
    assert(solution.sortVowels(givenS) == expectedAnswer);

    return 0;
}
