//#2273 Find Resultant Array After Removing Anagrams - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prev = "";
        for(auto &word : words)
        {
            string sortedW = word;
            sort(sortedW.begin(), sortedW.end());
            if(prev == sortedW)
                continue;
            prev = sortedW;
            result.push_back(word);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenWords = {"abba", "baba", "bbaa", "cd", "cd"};
    vector<string> expectedAnswer = {"abba", "cd"};
    assert(solution.removeAnagrams(givenWords) == expectedAnswer);

    givenWords = {"a", "b", "a"};
    expectedAnswer = {"a", "b", "a"};
    assert(solution.removeAnagrams(givenWords) == expectedAnswer);

    return 0;
}
