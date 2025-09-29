//#1039 Minimum Score Triangulation of Polygon - https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int computeScore(vector<int>& values, int dp[50][50], int vertexA = 0, int vertexB = 0){
        int result = 0;
        if(dp[vertexA][vertexB])
            return dp[vertexA][vertexB];
        for(int vertexC = vertexA + 1; vertexC < vertexB; vertexC++)
        {
            result = min(result == 0 ? INT_MAX : result, computeScore(values, dp, vertexA, vertexC) +
                         values[vertexA] * values[vertexB] * values[vertexC] +
                         computeScore(values, dp, vertexC, vertexB));
        }
        return dp[vertexA][vertexB] = result;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int dp[50][50] = {};
        return computeScore(values, dp, 0, values.size() - 1);
    }
};

int main()
{
    Solution solution;
    vector<int> givenValues = {1, 3, 1, 4, 1, 5};
    int expectedAnswer = 13;
    assert(solution.minScoreTriangulation(givenValues) == expectedAnswer);

    givenValues = {3, 7, 4, 5};
    expectedAnswer = 144;
    assert(solution.minScoreTriangulation(givenValues) == expectedAnswer);

    return 0;
}
