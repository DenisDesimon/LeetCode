//#3853 Merge Close Characters - https://leetcode.com/problems/merge-close-characters/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string mergeCharacters(string s, int k) {
        int count[26] = {0};
        string result = "";
        for(int i = 0; i < (int)s.size(); i++)
        {
            if((int)result.size() > k)
            {
                count[result[result.size() - k - 1] - 'a'] = 0;
            }
            if(count[s[i] - 'a'] == 0)
            {
                result += s[i];
                count[s[i] - 'a']++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "abca";
    int givenK = 3;
    string expectedAnswer = "abc";
    assert(solution.mergeCharacters(givenS, givenK) == expectedAnswer);

    givenS = "aabca";
    givenK = 2;
    expectedAnswer = "abca";
    assert(solution.mergeCharacters(givenS, givenK) == expectedAnswer);

    return 0;
}
