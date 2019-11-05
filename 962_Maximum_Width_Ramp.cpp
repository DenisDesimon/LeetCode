//#962 Maximum Width Ramp - https://leetcode.com/problems/maximum-width-ramp/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int, int>> B(A.size());
        int result = 0, min_idx = A.size();
        for(int i = 0; i < (int)A.size(); i++)
        {
            B[i].first = A[i], B[i].second = i;
        }
        sort(B.begin(), B.end());
        for(int i = 0; i < (int)B.size(); i++)
        {
            result = max(result, B[i].second - min_idx);
            min_idx = min(min_idx, B[i].second);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {6, 0, 8, 2, 1, 5};
    int expected_answer = 4;
    assert(solution.maxWidthRamp(given_A) == expected_answer);

    given_A = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    expected_answer = 7;
    assert(solution.maxWidthRamp(given_A) == expected_answer);

    return 0;
}
