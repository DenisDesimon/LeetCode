//#1096 Brace Expansion II - https://leetcode.com/problems/brace-expansion-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
    void dfs(string s, set<string> &result){
        int right = 0;
        for(; right < (int)s.size(); right++)
        {
            if(s[right] == '}')
                break;
        }
        if(right == (int)s.size())
        {
            result.insert(s);
            return;
        }
        int left = right;
        while(s[left] != '{')
            left--;
        string cur = "";
        for(int i = left + 1; i < right; i++)
        {
            if(s[i] == ',')
            {
                dfs(s.substr(0, left) + cur + s.substr(right + 1), result);
                cur = "";
            }
            else
                cur += s[i];
        }
        dfs(s.substr(0, left) + cur + s.substr(right + 1), result);
    }
public:
    vector<string> braceExpansionII(string expression) {
        set<string> result;
        dfs(expression, result);
        return vector<string>(result.begin(), result.end());
    }
};

int main()
{
    Solution solution;
    string givenExpression = "{a,b}{c,{d,e}}";
    vector<string> expectedAnswer = {"ac", "ad", "ae", "bc", "bd", "be"};
    assert(solution.braceExpansionII(givenExpression) == expectedAnswer);

    givenExpression = "{{a,z},a{b,c},{ab,z}}";
    expectedAnswer = {"a", "ab", "ac", "z"};
    assert(solution.braceExpansionII(givenExpression) == expectedAnswer);


    return 0;
}
