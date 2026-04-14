//#3899 Angles of a Triangle - https://leetcode.com/problems/angles-of-a-triangle/
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool compare(vector<double> answer, vector<double> expected){
    for(int i = 0; i < (int)answer.size(); i++)
    {
        if(abs(answer[i] - expected[i]) > 1e-5)
            return false;
    }
    return true;
}
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> result;
        int maxAngle = 0;
        int sumAngles = 0;
        for(auto &side : sides)
        {
            maxAngle = max(maxAngle, side);
            sumAngles += side;
        }
        if(maxAngle >= (sumAngles - maxAngle))
            return {};
        double pi = 2 * acos(0.0);
        double a = sides[0], b = sides[1], c = sides[2];
        result.push_back(acos((-c * c + a * a + b * b) / (2 * a * b)) * 180 / pi);
        result.push_back(acos((-b * b + a * a + c * c) / (2 * a * c)) * 180 / pi);
        result.push_back(acos((-a * a + c * c + b * b) / (2 * c * b)) * 180 / pi);
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenSides = {3, 4, 5};
    vector<double> expectedAnswer = {36.8699, 53.1301, 90};
    assert(compare(solution.internalAngles(givenSides), expectedAnswer));

    givenSides = {2, 4, 2};
    expectedAnswer = {};
    assert(compare(solution.internalAngles(givenSides), expectedAnswer));

    return 0;
}
