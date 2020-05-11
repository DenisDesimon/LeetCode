//#733 Flood Fill - https://leetcode.com/problems/flood-fill/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void fill(vector<vector<int>>& image, int row, int col, int newColor, int oldColor){
        if(image[row][col] != oldColor)
            return;
        image[row][col] = newColor;
        if(row > 0)
            fill(image, row - 1, col, newColor, oldColor);
        if(row < (int)image.size() - 1)
            fill(image, row + 1, col, newColor, oldColor);
        if(col > 0)
            fill(image, row, col - 1, newColor, oldColor);
        if(col < (int)image[0].size() - 1)
            fill(image, row, col + 1, newColor, oldColor);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image;
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_image = {{0, 0, 0}, {0, 1, 1}};
    int given_sr = 1;
    int given_sc = 1;
    int given_color = 1;
    vector<vector<int>> expected_answer = {{0, 0, 0}, {0, 1, 1}};
    assert(solution.floodFill(given_image, given_sr, given_sc, given_color) == expected_answer);

    given_image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    given_sr = 1;
    given_sc = 1;
    given_color = 2;
    expected_answer = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    assert(solution.floodFill(given_image, given_sr, given_sc, given_color) == expected_answer);

    return 0;
}
