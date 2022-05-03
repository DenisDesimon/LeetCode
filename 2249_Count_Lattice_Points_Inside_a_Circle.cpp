//#2249 Count Lattice Points Inside a Circle - https://leetcode.com/problems/count-lattice-points-inside-a-circle/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int hash[201][201] = {};
        int result = 0;
        for(auto &circle : circles)
        {
            for(int dx = circle[0] - circle[2]; dx <= circle[0] + circle[2]; dx++)
                result += ++hash[dx][circle[1]] == 1;
            int point = 1;
            for(int dy = 1; dy <= circle[2]; dy++)
            {
                while(dy * dy + (circle[2] - point) * (circle[2] - point) > circle[2] * circle[2])
                    point++;
                for(int dx = circle[0] - circle[2] + point; dx <= circle[0] + circle[2] - point; dx++)
                {
                    result += ++hash[dx][circle[1] + dy] == 1;
                    result += ++hash[dx][circle[1] - dy] == 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_circles = {{2, 2, 2}, {3, 4, 1}};
    int expected_answer = 16;
    assert(solution.countLatticePoints(given_circles) == expected_answer);

    given_circles = {{2,2,1}};
    expected_answer = 5;
    assert(solution.countLatticePoints(given_circles) == expected_answer);

    return 0;
}
