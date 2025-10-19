//#1625 Lexicographically Smallest String After Applying Operations - https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
#include <iostream>
#include <algorithm>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
private:
    void dfs(string s, int a, int b, unordered_set<string> &visited, string &result){
        if(visited.count(s))
            return;
        visited.insert(s);
        result = min(result, s);
        string reversed = s, addition = s;
        reverse(reversed.begin(), reversed.end());
        reverse(reversed.begin(), reversed.begin() + b);
        reverse(reversed.begin() + b, reversed.end());
        for(int i = 1; i < (int)addition.size(); i += 2)
            addition[i] = '0' + ((addition[i] - '0' + a) % 10);
        dfs(reversed, a, b, visited, result);
        dfs(addition, a, b, visited, result);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string result = s;
        dfs(s, a, b, visited, result);
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "5525";
    int givenA = 9;
    int givenB = 2;
    string expectedAnswer = "2050";
    assert(solution.findLexSmallestString(givenS, givenA, givenB) == expectedAnswer);

    givenS = "0011";
    givenA = 4;
    givenB = 2;
    expectedAnswer = "0011";
    assert(solution.findLexSmallestString(givenS, givenA, givenB) == expectedAnswer);

    return 0;
}
