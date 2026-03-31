//#3474 Lexicographically Smallest Generated String - https://leetcode.com/problems/lexicographically-smallest-generated-string/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string result(n + m - 1, 'a');
        vector<bool> isSet(n + m - 1);
        for(int i = 0; i < n; i++)
        {
            if(str1[i] == 'T')
            {
                for(int j = i; j < i + m; j++)
                {
                    if(isSet[j] && result[j] != str2[j - i])
                        return "";
                    isSet[j] = true;
                    result[j] = str2[j - i];
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(str1[i] == 'F')
            {
                int lastIdx = -1;
                int j = i;
                for(; j < i + m; j++)
                {
                    if(result[j] != str2[j - i])
                        break;
                    if(!isSet[j])
                    {
                        lastIdx = j;
                    }
                }
                if(j != i + m)
                    continue;
                if(lastIdx == -1)
                    return "";
                result[lastIdx] = 'b';
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenStr1 = "TFTF";
    string givenStr2 = "ab";
    string expectedAnswer = "ababa";
    assert(solution.generateString(givenStr1, givenStr2) == expectedAnswer);

    givenStr1 = "TFTF";
    givenStr2 = "abc";
    expectedAnswer = "";
    assert(solution.generateString(givenStr1, givenStr2) == expectedAnswer);

    return 0;
}
