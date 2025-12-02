//#3623 Count Number of Trapezoids I - https://leetcode.com/problems/count-number-of-trapezoids-i/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> heightCount;
        int mod = 1e9 + 7;
        long long result = 0, sum = 0;
        for(auto &point : points)
        {
            heightCount[point[1]]++;
        }
        for(auto height : heightCount)
        {
           long long countBases = (long long)height.second * (height.second - 1) / 2;
           result += sum * countBases;
           sum += countBases;
           result %= mod;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenPoints = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};
    long long expectedAnswer = 3;
    assert(solution.countTrapezoids(givenPoints) == expectedAnswer);

    givenPoints = {{0, 0}, {1, 0}, {0, 1}, {2, 1}};
    expectedAnswer = 1;
    assert(solution.countTrapezoids(givenPoints) == expectedAnswer);

    return 0;
}
