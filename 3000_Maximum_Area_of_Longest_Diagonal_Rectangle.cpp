//#3000 Maximum Area of Longest Diagonal Rectangle - https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int result = 0;
        long long diagonal = 0;
        for(auto &dimension : dimensions)
        {
            long long curD = dimension[0] * dimension[0] + dimension[1] * dimension[1];
            if(diagonal < curD)
            {
                diagonal = curD;
                result = dimension[0] * dimension[1];
            }
            else if(diagonal == curD)
                    result = max(result, dimension[0] * dimension[1]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenDimensions = {{10, 3}, {5, 9}, {8, 3}};
    int expectedAnswer = 30;
    assert(solution.areaOfMaxDiagonal(givenDimensions) == expectedAnswer);

    givenDimensions = {{2, 6}, {5, 1}, {3, 10}, {8, 4}};
    expectedAnswer = 30;
    assert(solution.areaOfMaxDiagonal(givenDimensions) == expectedAnswer);

    return 0;
}
