//#1653 Minimum Deletions to Make String Balanced - https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int result = 0;
        int countB = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'b')
                countB++;
            else
                result = min(result + 1, countB);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "aababbab";
    int expectedAnswer = 2;
    assert(solution.minimumDeletions(givenS) == expectedAnswer);

    givenS = "bbaaaaabb";
    expectedAnswer = 2;
    assert(solution.minimumDeletions(givenS) == expectedAnswer);


    return 0;
}
