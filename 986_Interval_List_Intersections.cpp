//#986 Interval List Intersections - https://leetcode.com/problems/interval-list-intersections/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        for(int i = 0, j = 0; i < (int)A.size() && j < (int)B.size(); )
        {
            if(A[i][1] < B[j][0])
                i++;
            else if(A[i][0] > B[j][1])
                j++;
            else
            {
                result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                if(A[i][1] > B[j][1])
                    j++;
                else
                    i++;
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_a = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> given_b = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};
    vector<vector<int>> expected_answer = {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}};
    assert(solution.intervalIntersection(given_a, given_b) == expected_answer);

    given_a = {{1, 2}, {3, 3}, {4, 5}, {6, 9}};
    given_b = {{0, 0}, {1, 3}, {4, 9}};
    expected_answer = {{1, 2}, {3, 3}, {4, 5}, {6, 9}};
    assert(solution.intervalIntersection(given_a, given_b) == expected_answer);

    return 0;
}
