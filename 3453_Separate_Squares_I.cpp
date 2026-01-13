//#3453 Separate Squares I - https://leetcode.com/problems/separate-squares-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalSquare = 0;
        int maxY = INT_MIN;
        for(auto &square : squares)
        {
            totalSquare += (double)square[2] * square[2];
            maxY = max(maxY, square[1] + square[2]);
        }
        auto isMid = [&] (double curY) -> bool
        {
            double curSquare = 0;
            for(auto &square : squares)
            {
                if(square[1] < curY)
                {
                    curSquare += (double)square[2] * min((double)square[2], curY - square[1]);
                }
            }
            return curSquare >= totalSquare / 2;
        };
        double bottom = 0, top = maxY;
        double precise = 1e-5;
        while((top - bottom) >= precise)
        {
            double mid = (top - bottom) / 2 + bottom;
            if(isMid(mid))
                top = mid;
            else
                bottom = mid;
        }
        return top;
    }
};

int main()
{
    Solution solution;
    double precise = 1e-5;
    vector<vector<int>> givenSquares = {{0, 0, 1}, {2, 2, 1}};
    double expectedAnswer = 1.0;
    assert(abs(solution.separateSquares(givenSquares) - expectedAnswer) < precise);

    givenSquares = {{0, 0, 2}, {1, 1, 1}};
    expectedAnswer = 1.16667;
    assert(abs(solution.separateSquares(givenSquares) - expectedAnswer) < precise);

    return 0;
}
