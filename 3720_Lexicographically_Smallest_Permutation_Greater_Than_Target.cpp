//#3720 Lexicographically Smallest Permutation Greater Than Target - https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
#include <iostream>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int count[26] = {0};
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;
            count[target[i] - 'a']--;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            int cur = target[i] - 'a';
            count[cur]++;
            int minLetter = INT_MAX;
            for(auto &letter : count)
                minLetter = min(minLetter, letter);
            if(minLetter < 0)
                continue;
            for(int j = cur + 1; j < 26; j++)
            {
                if(count[j])
                {
                    target[i] = 'a' + j;
                    count[j]--;
                    target.resize(i + 1);
                    for(int t = 0; t < 26; t++)
                        target += string(count[t], 'a' + t);
                    return target;
                }
            }
        }
        return "";
    }
};

int main()
{
    Solution solution;
    string givenS = "abc";
    string givenTarget = "bba";
    string expectedAnswer = "bca";
    assert(solution.lexGreaterPermutation(givenS, givenTarget) == expectedAnswer);

    givenS = "leet";
    givenTarget = "code";
    expectedAnswer = "eelt";
    assert(solution.lexGreaterPermutation(givenS, givenTarget) == expectedAnswer);


    return 0;
}
