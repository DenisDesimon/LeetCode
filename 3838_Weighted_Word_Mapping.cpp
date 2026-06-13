//#3838 Weighted Word Mapping - https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13
#include <iostream>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;
        for(auto &word : words)
        {
            int sum = 0;
            for(auto &letter : word)
            {
                sum += weights[letter - 'a'];
            }
            result += 'a' + (25 - sum % 26);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenWords = {"abcd", "def", "xyz"};
    vector<int> givenWeights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    string expectedAnswer = "rij";
    assert(solution.mapWordWeights(givenWords, givenWeights) == expectedAnswer);

    givenWords = {"a", "b", "c"};
    givenWeights = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    expectedAnswer = "yyy";
    assert(solution.mapWordWeights(givenWords, givenWeights) == expectedAnswer);

    return 0;
}
