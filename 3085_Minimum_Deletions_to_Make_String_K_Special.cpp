//#3085 Minimum Deletions to Make String K-Special - https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> alphabet(26, 0);
        int result = INT_MAX;
        int deletedCount = 0;
        for(auto &letter : word)
        {
            alphabet[letter - 'a']++;
        }
        sort(alphabet.begin(), alphabet.end());
        for(int i = 0; i < (int)alphabet.size(); i++)
        {
            if(alphabet[i] == 0)
                continue;
            int localRes = deletedCount;
            for(int j = (int)alphabet.size() - 1; j > i; j--)
            {
                if(alphabet[j] - alphabet[i] <= k)
                    break;
                localRes += alphabet[j] - alphabet[i] - k;
            }
            deletedCount += alphabet[i];
            result = min(result, localRes);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_word = "aabcaba";
    int given_k = 0;
    int expected_answer = 3;
    assert(solution.minimumDeletions(given_word, given_k) == expected_answer);

    given_word = "aaabaaa";
    given_k = 2;
    expected_answer = 1;
    assert(solution.minimumDeletions(given_word, given_k) == expected_answer);

    return 0;
}

