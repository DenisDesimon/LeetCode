//#1792 Maximum Average Pass Ratio - https://leetcode.com/problems/maximum-average-pass-ratio/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double result = 0, maxChange = 0;
        auto comp = [](pair<int, int> &left, pair<int, int> &right) {
               return ((double)(left.first + 1) / (left.second + 1) - (double)left.first / left.second) <
                       ((double)(right.first + 1) / (right.second + 1) - (double)right.first / right.second);
           };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> highestChange(comp);
        for(int i = 0; i < (int)classes.size(); i++)
        {
            result += (double)classes[i][0] / classes[i][1];
            highestChange.push({classes[i][0], classes[i][1]});
        }
        while(extraStudents){
            auto temp = highestChange.top();
            maxChange += (double)(highestChange.top().first + 1) / (highestChange.top().second + 1)
                    - (double)(highestChange.top().first) / (highestChange.top().second);
            extraStudents--;
            highestChange.pop();
            highestChange.push({temp.first + 1, temp.second + 1});
        }
        return (result + maxChange) / classes.size();
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenClasses = {{1, 2}, {3, 5}, {2 ,2}};
    int givenExtraStudents = 2;
    double expectedAnswer = 0.783333;
    assert(abs(solution.maxAverageRatio(givenClasses, givenExtraStudents) - expectedAnswer) < 0.0001);

    givenClasses = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    givenExtraStudents = 4;
    expectedAnswer = 0.53485;
    assert(abs(solution.maxAverageRatio(givenClasses, givenExtraStudents) - expectedAnswer) < 0.0001);

    return 0;
}
