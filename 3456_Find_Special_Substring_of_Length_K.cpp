//#3456 Find Special Substring of Length K - https://leetcode.com/problems/find-special-substring-of-length-k/
#include <iostream>
#include <cassert>
using namespace std;

class Solution{
public:
    bool hasSpecialSubstring(string s, int k){
        int left = 0;
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(s[left] == s[i])
                continue;
            if(i - left == k)
                return true;
            left = i;
        }
        return (int)s.size() - left == k;
    }
};

int main()
{
    Solution solution;
    string givenS = "aaabaaa";
    int givenK = 3;
    bool expectedAnswer = true;
    assert(solution.hasSpecialSubstring(givenS, givenK) == expectedAnswer);

    givenS = "a";
    givenK = 1;
    expectedAnswer = true;
    assert(solution.hasSpecialSubstring(givenS, givenK) == expectedAnswer);

    return 0;
}
