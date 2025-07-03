//#3333 Find the Original Typed String II - https://leetcode.com/problems/find-the-original-typed-string-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int mod = 1000000000 + 7;
public:
    int possibleStringCount(string word, int k) {
        long long result = 1;
        vector<int> countGroups;
        int count = 1;
        for(int i = 1; i < (int)word.size(); i++)
        {
            if(word[i] == word[i - 1])
                count++;
            else
            {
                countGroups.push_back(count);
                count = 1;
            }
        }
        countGroups.push_back(count);
        for(auto &group : countGroups)
            result = (result * group) % mod;
        if((int)countGroups.size() >= k)
            return result;
        vector<long long> prefixSum(k, 1);
        for(auto &freq : countGroups)
        {
            vector<long long> currentGroup(k, 0);
            for(int maxLength = 1; maxLength < k; maxLength++)
            {
                currentGroup[maxLength] = prefixSum[maxLength - 1];
                if(maxLength - freq - 1 >= 0)
                {
                    currentGroup[maxLength] = (currentGroup[maxLength] - prefixSum[maxLength - freq - 1] + mod) % mod;
                }
            }
            prefixSum[0] = 0;
            for(int i = 1; i < k; i++)
            {
                prefixSum[i] = (prefixSum[i - 1] + currentGroup[i]) % mod;
            }
        }
        return (result - prefixSum.back() + mod) % mod;
    }
};


int main()
{
    Solution solution;
    string given_word = "wwwwwwwbbbbssssssssvvoooooooqqqqqqqqqvvvvvooooooocccccppppkkkkkkjnddddddbbb";
    int given_k = 50;
    int expected_answer = 497563975;
    assert(solution.possibleStringCount(given_word, given_k) == expected_answer);

    given_word = "aabbccdd";
    given_k = 7;
    expected_answer = 5;
    assert(solution.possibleStringCount(given_word, given_k) == expected_answer);

    return 0;
}
