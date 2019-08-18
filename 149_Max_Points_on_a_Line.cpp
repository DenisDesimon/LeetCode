//#149 Max Points on a Line - https://leetcode.com/problems/max-points-on-a-line/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        int n = points.size();
        sort(points.begin(), points.end());
        int result = 0;
        map<pair<pair<long long, long long>, pair<long long, long long>>, int> line_equality;
        pair<long long, long long> a, b;
        int point_equal = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && points[i - 1] == points[i])
            {
                point_equal++;
                continue;
            }
            else
                point_equal = 0;
            for(int j = i + 1; j < n; j++)
            {
                if(points[i] == points[j])
                {
                    point_equal++;
                    continue;
                }
                if(points[i][0] - points[j][0] == 0)
                    b = {0, 1};
                else
                {
                    long long left = (long long)points[i][0] * (long long)points[j][1] - (long long)points[i][1] * (long long)points[j][0];
                    long long right = (points[i][0] - points[j][0]);
                    long long greater_cd = gcd(left, right);
                    b = {left / greater_cd, right / greater_cd};
                }
                if(points[i][0] == 0)
                {
                    if(points[j][0] == 0)
                        a = {0, 1};
                    else
                    {
                        long long left = points[j][1] - b.first / b.second;
                        long long right = points[j][0];
                        long long greater_cd = gcd(left, right);
                        a = {left / greater_cd, right / greater_cd};;
                    }
                }
                else
                {
                    long long left = points[i][1] - b.first / b.second;
                    long long right = points[i][0];
                    long long greater_cd = gcd(left, right);
                    a = {left / greater_cd, right / greater_cd};;
                }
                pair<pair<long long, long long>, pair<long long, long long>> idx = {a, b};
                line_equality[idx]++;
                result = max(result, line_equality[idx] + point_equal);
            }
            result = max(result, point_equal);
            line_equality.clear();

        }
        return result + 1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{0, 0}, {94911151, 94911150}, {94911152, 94911151}};
    int expected_answer = 2;
    assert(solution.maxPoints(given_points) == expected_answer);

    given_points = {{1, 1}, {2, 2}, {3, 3}};
    expected_answer = 3;
    assert(solution.maxPoints(given_points) == expected_answer);

    return 0;
}
