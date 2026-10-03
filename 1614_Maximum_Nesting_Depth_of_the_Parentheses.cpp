//#1614 Maximum Nesting Depth of the Parentheses - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int result = 0, count = 0;
        for(auto &letter : s)
        {
            if(letter == '(')
                count++;
            else if(letter == ')')
                count--;
            result = max(result, count);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "(1+(2*3)+((8)/4))+1";
    int expectedAnswer = 3;
    assert(solution.maxDepth(givenS) == expectedAnswer);

    givenS = "()(())((()()))";
    expectedAnswer = 3;
    assert(solution.maxDepth(givenS) == expectedAnswer);

    return 0;
}
