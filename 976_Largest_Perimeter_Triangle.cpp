//#976 Largest Perimeter Triangle - https://leetcode.com/problems/largest-perimeter-triangle/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for(int i = A.size() - 1; i > 1; i--)
        {
            if(A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {2, 1, 2};
    int expected_answer = 5;
    assert(solution.largestPerimeter(given_A) == expected_answer);

    given_A = {3, 6, 2, 3};
    expected_answer = 8;
    assert(solution.largestPerimeter(given_A) == expected_answer);

    return 0;
}
