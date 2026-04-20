//#2078 Two Furthest Houses With Different Colors - https://leetcode.com/problems/two-furthest-houses-with-different-colors/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int result = 0;
        int n = colors.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i + result + 1; j < n; j++)
            {
                if(colors[i] != colors[j])
                    result = j - i;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenColors = {1, 1, 1, 6, 1, 1, 1};
    int expectedAnswer = 3;
    assert(solution.maxDistance(givenColors) == expectedAnswer);

    givenColors = {0, 1};
    expectedAnswer = 1;
    assert(solution.maxDistance(givenColors) == expectedAnswer);

    return 0;
}
