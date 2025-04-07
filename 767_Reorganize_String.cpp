//#767 Reorganize String - https://leetcode.com/problems/reorganize-string/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution{
public:
    string reorganizeString(string s){
        vector<int> letterCount(26, 0);
        string result = "";
        for(auto &letter : s)
            letterCount[letter - 'a']++;
        priority_queue<pair<int, char>> freqLetters;
        for(int i = 0; i < 26; i++)
        {
            if(letterCount[i] != 0)
                freqLetters.emplace(letterCount[i], char(i + 'a'));
        }
        while(!freqLetters.empty())
        {
            pair<int, char> mostFreqLett = freqLetters.top();
            pair<int, char> secondFreqLett;
            freqLetters.pop();
            result.push_back(mostFreqLett.second);
            mostFreqLett.first--;
            if(!freqLetters.empty())
            {
                secondFreqLett = freqLetters.top();
                freqLetters.pop();
                result.push_back(secondFreqLett.second);
                secondFreqLett.first--;
            }
            else if(mostFreqLett.first == 0)
                return result;
            else
                return "";
            if(mostFreqLett.first != 0)
                freqLetters.emplace(mostFreqLett);
            if(secondFreqLett.first != 0)
                freqLetters.emplace(secondFreqLett);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "aab";
    string expectedAnswer = "aba";
    assert(solution.reorganizeString(givenS) == expectedAnswer);

    givenS = "aaab";
    expectedAnswer = "";
    assert(solution.reorganizeString(givenS) == expectedAnswer);

    return 0;
}
