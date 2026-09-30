//#1111 Maximum Nesting Depth of Two Valid Parentheses Strings - https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> result;
        for(auto &parentheses : seq)
        {
            if(parentheses == '(')
            {
                depth++;
                result.push_back(depth % 2);
            }
            else
            {
                result.push_back(depth % 2);
                depth--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenSeq = "(()())";
    vector<int> expectedAnswer = {1, 0, 0, 0, 0, 1};
    assert(solution.maxDepthAfterSplit(givenSeq) == expectedAnswer);

    givenSeq = "()(())()";
    expectedAnswer = {1, 1, 1, 0, 0, 1, 1, 1};
    assert(solution.maxDepthAfterSplit(givenSeq) == expectedAnswer);

    return 0;
}
