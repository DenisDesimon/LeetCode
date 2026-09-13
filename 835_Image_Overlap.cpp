//#835 Image Overlap - https://leetcode.com/problems/image-overlap/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(img1[i][j])
                    ones1.push_back({i, j});
                if(img2[i][j])
                    ones2.push_back({i, j});
            }
        }
        vector<vector<int>> countSlides(n * 2, vector<int> (n * 2));
        int result = 0;
        for(auto &one1: ones1)
        {
            for(auto &one2: ones2)
            {
                int dx = one1.first - one2.first + n;
                int dy = one1.second - one2.second + n;
                result = max(result, ++countSlides[dx][dy]);
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenImg1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> givenImg2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    int expectedAnswer = 3;
    assert(solution.largestOverlap(givenImg1, givenImg2) == expectedAnswer);

    givenImg1 = {{1}};
    givenImg2 = {{1}};
    expectedAnswer = 1;
    assert(solution.largestOverlap(givenImg1, givenImg2) == expectedAnswer);


    return 0;
}
