//#717 1-bit and 2-bit Characters - https://leetcode.com/problems/1-bit-and-2-bit-characters/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        for(; i < (int)bits.size() - 1; )
        {
            if(bits[i] == 1)
            {
                i++;
            }
            i++;
        }
        return i == (int)bits.size() - 1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenBits = {1, 0, 0};
    bool expectedAnswer = true;
    assert(solution.isOneBitCharacter(givenBits) == expectedAnswer);

    givenBits = {1, 1, 1, 0};
    expectedAnswer = false;
    assert(solution.isOneBitCharacter(givenBits) == expectedAnswer);

    return 0;
}
