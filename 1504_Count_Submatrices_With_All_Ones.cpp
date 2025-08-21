//#1504 Count Submatrices With All Ones - https://leetcode.com/problems/count-submatrices-with-all-ones/
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int col = mat.front().size();
        vector<int> heights(col);
        int result = 0;
        for(auto &rows : mat)
        {
            stack<vector<int>> prevLowHeights;
            prevLowHeights.push({-1, 0, -1});
            for(int right = 0; right < col; right++)
            {
                heights[right] = rows[right] == 0 ? 0 : heights[right] + 1;
                int height = heights[right];
                while(prevLowHeights.top()[2] >= height)
                    prevLowHeights.pop();
                int left = prevLowHeights.top()[0];
                int prevSum = prevLowHeights.top()[1];
                int curSum = prevSum + (right - left) * height;
                prevLowHeights.push({right, curSum, height});
                result += curSum;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenMat = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    int expectedAnswer = 24;
    assert(solution.numSubmat(givenMat) == expectedAnswer);

    givenMat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    expectedAnswer = 13;
    assert(solution.numSubmat(givenMat) == expectedAnswer);

    return 0;
}
