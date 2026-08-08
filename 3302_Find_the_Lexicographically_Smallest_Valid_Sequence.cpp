//#3302 Find the Lexicographically Smallest Valid Sequence - https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> rightMost(m, -1);
        int j = m - 1;
        for(int i = n - 1; i >= 0 && j >= 0; i--)
        {
            if(word1[i] == word2[j])
                rightMost[j--] = i;
        }
        vector<int> result;
        bool isReplaced = false;
        j = 0;
        for(int i = 0; i < n && j < m; i++)
        {
            if(word1[i] == word2[j] || (!isReplaced && (j == m - 1 || i < rightMost[j + 1])))
            {
                isReplaced = isReplaced || word1[i] != word2[j];
                result.push_back(i);
                j++;
            }
        }
        return j == m ? result : vector<int>();
    }
};

int main()
{
    Solution solution;
    string givenWord1 = "vbcca";
    string givenWord2 = "abc";
    vector<int> expectedAnswer = {0, 1, 2};
    assert(solution.validSequence(givenWord1, givenWord2) == expectedAnswer);

    givenWord1 = "bacdc";
    givenWord2 = "abc";
    expectedAnswer = {1, 2, 4};
    assert(solution.validSequence(givenWord1, givenWord2) == expectedAnswer);

    return 0;
}
