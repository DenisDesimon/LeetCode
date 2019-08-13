//#120 Triangle - https://leetcode.com/problems/triangle/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        int result = INT_MAX;
        for(int i = 1; i < (int)triangle.size(); i++)
        {
            for(int j = 0; j < (int)triangle[i].size(); j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i - 1][j];
                else if(j == (int)triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                if(i == (int)triangle.size() - 1)
                    result = min(result, triangle[i][j]);
            }
        }
        return result == INT_MAX ? triangle[0][0] : result;
    }
};

int main()
{
    Solution solutin;
    vector<vector<int>> given_triangle = {{-10}};
    int expected_answer = -10;
    assert(solutin.minimumTotal(given_triangle) == expected_answer);

    given_triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    expected_answer = 11;
    assert(solutin.minimumTotal(given_triangle) == expected_answer);

    return 0;
}
