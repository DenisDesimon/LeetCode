//#1541 Minimum Insertions to Balance a Parentheses String  - https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int result = 0;
        int count = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;
            else
            {
                if(count > 0)
                    count--;
                else
                    result++;
                if(i + 1 < n && s[i + 1] == ')')
                    i++;
                else
                    result++;
            }
        }
        return result + count * 2;
    }
};

int main()
{
    Solution solution;
    string givenS  = "(()))";
    int expectedAnswer = 1;
    assert(solution.minInsertions(givenS) == expectedAnswer);

    givenS = "))())(";
    expectedAnswer = 3;
    assert(solution.minInsertions(givenS) == expectedAnswer);

    return 0;
}
