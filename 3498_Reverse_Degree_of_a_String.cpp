//#3498 Reverse Degree of a String - https://leetcode.com/problems/reverse-degree-of-a-string/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for(int i = 0; i < (int)s.size(); i++)
            result += (26 - (s[i] - 'a')) * (i + 1);
        return  result;
    }
};

int main()
{
    Solution solution;
    string givenS = "abc";
    int expectedAnswer = 148;
    assert(solution.reverseDegree(givenS) == expectedAnswer);

    givenS = "zaza";
    expectedAnswer = 160;
    assert(solution.reverseDegree(givenS) == expectedAnswer);


    return 0;
}
