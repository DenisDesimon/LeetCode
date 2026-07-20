//#3998 Transform Binary String Using Subsequence Sort - https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> result;
        int n = s.size();
        vector<int> prefixZero(n + 1);
        for(int i = 0; i < n; i++)
            prefixZero[i + 1] = prefixZero[i] + (s[i] == '0');
        int totalZeroes = prefixZero[n];
        for(auto &str : strs)
        {
            int countZero = 0;
            int countQuest = 0;
            for(int i = 0; i < n; i++)
            {
                if(str[i] == '?')
                    countQuest++;
                else if(str[i] == '0')
                    countZero++;
            }
            int questionToZero = totalZeroes - countZero;
            if(questionToZero < 0 || questionToZero > countQuest)
            {
                result.push_back(false);
                continue;
            }
            countZero = 0;
            int i = 0;
            for(; i < n; i++)
            {
                if(str[i] == '?')
                {
                    if(questionToZero > 0)
                    {
                        questionToZero--;
                        countZero++;
                    }
                }
                else if(str[i] == '0')
                    countZero++;
                if(countZero < prefixZero[i + 1])
                    break;
            }
            if(i != n)
            {
                result.push_back(false);
                continue;
            }
            result.push_back(!questionToZero);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "101";
    vector<string> givenStrs = {"1?1", "0?1", "0?0"};
    vector<bool> expectedAnswer = {true, true, false};
    assert(solution.transformStr(givenS, givenStrs) == expectedAnswer);

    givenS = "1100";
    givenStrs = {"0011", "11?1", "1?1?"};
    expectedAnswer = {true, false, true};
    assert(solution.transformStr(givenS, givenStrs) == expectedAnswer);

    return 0;
}
