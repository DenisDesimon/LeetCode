//#1807 Evaluate the Bracket Pairs of a String - https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> brackets;
        for(auto &bracket : knowledge)
            brackets[bracket[0]] = bracket[1];
        string result;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '(')
            {
                string cur = "";
                while(s[++i] != ')')
                    cur += s[i];
                if(brackets.count(cur))
                    result += brackets[cur];
                else
                    result += '?';
            }
            else
                result += s[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> givenKnowledge = {{"name", "bob"}, {"age", "two"}};
    string givenS = "(name)is(age)yearsold";
    string expectedAnswer = "bobistwoyearsold";
    assert(solution.evaluate(givenS, givenKnowledge) == expectedAnswer);

    givenKnowledge = {{"a"}, {"b"}};
    givenS = "hi(name)";
    expectedAnswer = "hi?";
    assert(solution.evaluate(givenS, givenKnowledge) == expectedAnswer);


    return 0;
}
