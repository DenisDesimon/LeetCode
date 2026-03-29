//#2839 Check if Strings Can be Made Equal With Operations I - https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i = 0; i < 4; i++)
        {
            if(s1[i] != s2[i])
            {
                if(i < 2 && s1[i + 2] == s2[i])
                {
                    swap(s1[i], s1[i + 2]);
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string givenS1 = "abcd";
    string givenS2 = "cdab";
    bool expectedAnswer = true;
    assert(solution.canBeEqual(givenS1, givenS2) == expectedAnswer);

    givenS1 = "abcd";
    givenS2 = "dacb";
    expectedAnswer = false;
    assert(solution.canBeEqual(givenS1, givenS2) == expectedAnswer);

    return 0;
}
