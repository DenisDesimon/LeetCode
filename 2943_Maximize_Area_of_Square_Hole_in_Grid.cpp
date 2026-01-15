//#2943 Maximize Area of Square Hole in Grid - https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxConsecutiveHor = 1, maxConsecutiveVert = 1;
        int cur = 1;
        for(int i = 1; i < (int)hBars.size(); i++)
        {
            if(hBars[i] == hBars[i - 1] + 1)
                cur++;
            else
                cur = 1;
            maxConsecutiveHor = max(maxConsecutiveHor, cur);
        }
        cur = 1;
        for(int i = 1; i < (int)vBars.size(); i++)
        {
            if(vBars[i] == vBars[i - 1] + 1)
                cur++;
            else
                cur = 1;
            maxConsecutiveVert = max(maxConsecutiveVert, cur);
        }
        int len = min(maxConsecutiveVert, maxConsecutiveHor) + 1;
        return len * len;
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    int givenM = 1;
    vector<int> givenHBars = {2, 3};
    vector<int> givenVBars = {2};
    int expectedAnswer = 4;
    assert(solution.maximizeSquareHoleArea(givenN, givenM, givenHBars, givenVBars) == expectedAnswer);

    givenN = 2;
    givenM = 1;
    givenHBars = {3, 2, 4};
    givenVBars = {3, 2};
    expectedAnswer = 9;
    assert(solution.maximizeSquareHoleArea(givenN, givenM, givenHBars, givenVBars) == expectedAnswer);

    return 0;
}
