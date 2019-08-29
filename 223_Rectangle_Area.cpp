//#223 Rectangle Area - https://leetcode.com/problems/rectangle-area/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int square_first = (C - A) * (D - B), square_second = (G - E) * (H - F);
        int left = max(A, E), right = min(G, C), bottom = max(F, B), top = min(D, H);
        int common_area = 0;
        if(right > left && top > bottom)
            common_area = (right - left) * (top - bottom);
        return square_first - common_area + square_second;
    }
};

int main()
{
    Solution solution;
    pair<int, int> given_first_bottom = {-2, -2};
    pair<int, int> given_first_top = {2, 2};
    pair<int, int> given_second_bottom = {-2, -2};
    pair<int, int> given_second_top = {2, 2};
    int expected_answer = 16;
    assert(solution.computeArea(given_first_bottom.first, given_first_bottom.second,
                                given_first_top.first, given_first_top.second,
                                given_second_bottom.first, given_second_bottom.second,
                                given_second_top.first, given_second_top.second) == expected_answer);

    return 0;
}
