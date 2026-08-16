//#2029 Stone Game IX - https://leetcode.com/problems/stone-game-ix/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(auto &stone : stones)
        {
            if(stone % 3 == 0)
                count0++;
            else if(stone % 3 == 1)
                count1++;
            else
                count2++;
        }
        if(count0 % 2 == 0)
            return count1 >= 1 && count2 >= 1;
        return count1 - count2 > 2 || count2 - count1 > 2;
    }
};

int main()
{
    Solution solution;
    vector<int> givenStones = {5, 1, 2, 4, 3};
    bool expectedAnswer = false;
    assert(solution.stoneGameIX(givenStones) == expectedAnswer);

    givenStones = {2, 1};
    expectedAnswer = true;
    assert(solution.stoneGameIX(givenStones) == expectedAnswer);


    return 0;
}
