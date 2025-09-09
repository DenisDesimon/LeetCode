//#2327 Number of People Aware of a Secret  - https://leetcode.com/problems/number-of-people-aware-of-a-secret/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> knows(n + 1), shares(n + 1);
        knows[1] = 1;
        int cntKnows = 1, cntShares = 0;
        for(int i = 2; i <= n; i++)
        {
            if(i > delay)
            {
                cntKnows = (cntKnows - knows[i - delay] + mod) % mod;
                cntShares = (cntShares + knows[i - delay]) % mod;
                shares[i - delay] = knows[i - delay];
            }
            if(i > forget)
                cntShares = (cntShares - shares[i - forget] + mod) % mod;
            if(i > delay)
            {
                cntKnows = (cntKnows + cntShares) % mod;
                knows[i] = cntShares;
            }
        }
        return (cntKnows + cntShares) % mod;
    }
};

int main()
{
    Solution solution;
    int givenN = 6;
    int givenDelay = 2;
    int givenForget = 4;
    int expectedAnswer = 5;
    assert(solution.peopleAwareOfSecret(givenN, givenDelay, givenForget) == expectedAnswer);

    givenN = 4;
    givenDelay = 1;
    givenForget = 3;
    expectedAnswer = 6;
    assert(solution.peopleAwareOfSecret(givenN, givenDelay, givenForget) == expectedAnswer);

    return 0;
}
