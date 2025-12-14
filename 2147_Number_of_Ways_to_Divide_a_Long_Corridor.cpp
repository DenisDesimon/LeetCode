//#2147 Number of Ways to Divide a Long Corridor - https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        long long result = 1;
        int mod = 1e9 +7;
        int countSeats = 0, prev = -1;
        for(int i = 0; i < (int)corridor.size(); i++)
        {
            if(corridor[i] == 'S')
            {
                countSeats++;
                if(countSeats == 2)
                {
                    prev = i;
                    countSeats = 0;
                }
                else if(prev != -1)
                {
                    result *= (i - prev);
                    result %= mod;
                }
            }
        }
        if(countSeats == 1 || prev == -1)
            return 0;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenCorridor = "SSPPSPS";
    int expectedAnswer = 3;
    assert(solution.numberOfWays(givenCorridor) == expectedAnswer);

    givenCorridor = "PPSPSP";
    expectedAnswer = 1;
    assert(solution.numberOfWays(givenCorridor) == expectedAnswer);

    return 0;
}
