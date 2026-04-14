//#3898 Find the Degree of Each Vertex - https://leetcode.com/problems/find-the-degree-of-each-vertex/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j])
                {
                    result[i]++;
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenMatrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    vector<int> expected_answer = {2, 2, 2};
    assert(solution.findDegrees(givenMatrix) == expected_answer);

    givenMatrix = {{0, 1, 0}, {1, 0, 0}, {0, 0, 0}};
    expected_answer = {1, 1, 0};
    assert(solution.findDegrees(givenMatrix) == expected_answer);

    return 0;
}
