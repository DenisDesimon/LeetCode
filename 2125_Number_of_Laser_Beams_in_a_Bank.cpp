//#2125 Number of Laser Beams in a Bank - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prev = 0;
        for(auto &row : bank)
        {
            int cur = 0;
            for(auto &col : row)
            {
                result += prev * (col - '0');
                cur += col - '0';
            }
            prev = cur == 0 ? prev : cur;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenBank = {"011001", "000000", "010100", "001000"};
    int expectedAnswer = 8;
    assert(solution.numberOfBeams(givenBank) == expectedAnswer);

    givenBank = {"000", "111", "000"};
    expectedAnswer = 0;
    assert(solution.numberOfBeams(givenBank) == expectedAnswer);

    return 0;
}
