//#1871 Jump Game VII - https://leetcode.com/problems/jump-game-vii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n);
        if(s[n - 1] == '0')
            dp[n - 1] = true;
        else
            return false;
        int bounder = n - 1 - minJump;
        for(int i = n - 1; i >= 0; i--)
        {
            if(!dp[i])
                continue;
            for(int j = min(bounder, i - minJump); j >= 0 && j >= i - maxJump; j--)
            {
                if(s[j] == '0')
                    dp[j] = true;
            }
            bounder = i - maxJump + 1;
        }
        return dp.front();
    }
};

int main()
{
    Solution solution;
    string givenS  = "011010";
    int givenMinJump = 2;
    int givenMaxJump = 3;
    bool expectedAnswer = true;
    assert(solution.canReach(givenS, givenMinJump, givenMaxJump) == expectedAnswer);

    givenS  = "01101110";
    givenMinJump = 2;
    givenMaxJump = 3;
    expectedAnswer = false;
    assert(solution.canReach(givenS, givenMinJump, givenMaxJump) == expectedAnswer);

    return 0;
}
