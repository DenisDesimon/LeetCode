//#799 Champagne Tower - https://leetcode.com/problems/champagne-tower/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cups(query_row + 2, vector<double> (query_row + 3, 0));
        cups[0][0] = (double)poured;
        for(int i = 0; i <= query_row; i++)
        {
            for(int j = 0; j < i + 1; j++)
            {
                if(cups[i][j] > 1)
                {
                    double overFlow = (cups[i][j] - 1) / 2;
                    cups[i + 1][j] += overFlow;
                    cups[i + 1][j + 1] += overFlow;
                    cups[i][j] = 1;
                }
            }
        }
        return cups[query_row][query_glass];
    }
};

int main()
{
    Solution solution;
    int givenPoured = 2;
    int givenRow = 1;
    int givenColl = 1;
    double expectedAnswer = 0.5;
    double epsilon = 1e-9;
    assert(abs(solution.champagneTower(givenPoured, givenRow, givenColl) - expectedAnswer) < epsilon);

    givenPoured = 100000009;
    givenRow = 33;
    givenColl = 17;
    expectedAnswer = 1;
    assert(abs(solution.champagneTower(givenPoured, givenRow, givenColl) - expectedAnswer) < epsilon);

    return 0;
}
