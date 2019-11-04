//#1232 Check If It Is a Straight Line - https://leetcode.com/problems/check-if-it-is-a-straight-line/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int a,b;
        if(coordinates[0][0] == coordinates[1][0])
        {
            for(int i = 2; i < (int)coordinates.size(); i++)
            {
                if(coordinates[i][0] != coordinates[i - 1][0])
                    return false;
            }
            return true;
        }
        if(coordinates[0][0] == 0)
        {
            b = coordinates[0][1];
            a = (coordinates[1][1] - b) / coordinates[1][0];
        }
        else
        {
            b = (coordinates[1][1] * coordinates[0][0] - coordinates[0][1] * coordinates[1][0]) / (coordinates[0][0] - coordinates[1][0]);
            a = (coordinates[0][1] - b) / coordinates[0][0];
        }
        for(int i = 2; i < (int)coordinates.size(); i++)
        {
            if(coordinates[i][1] != a * coordinates[i][0] + b)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    bool expected_answer = false;
    assert(solution.checkStraightLine(given_coordinates) == expected_answer);

    given_coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6,7}};
    expected_answer = true;
    assert(solution.checkStraightLine(given_coordinates) == expected_answer);

    return 0;
}
