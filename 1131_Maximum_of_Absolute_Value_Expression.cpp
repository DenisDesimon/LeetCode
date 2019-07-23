//#1131 Maximum of Absolute Value Expression - https://leetcode.com/problems/maximum-of-absolute-value-expression/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int> case1(arr1.size()), case2(arr1.size()), case3(arr1.size()), case4(arr1.size());
        int max_case1 = INT_MIN, min_case1 = INT_MAX, max_case2 = INT_MIN, min_case2 = INT_MAX;
        int max_case3 = INT_MIN, min_case3 = INT_MAX, max_case4 = INT_MIN, min_case4 = INT_MAX;
        for(int i = 0; i < (int)arr1.size(); i++)
        {
            case1[i] = arr1[i] + arr2[i] + i;
            max_case1 = max(max_case1, case1[i]);
            min_case1 = min(min_case1, case1[i]);
            case2[i] = arr1[i] + arr2[i] - i;
            max_case2 = max(max_case2, case2[i]);
            min_case2 = min(min_case2, case2[i]);
            case3[i] = arr1[i] - arr2[i] + i;
            max_case3 = max(max_case3, case3[i]);
            min_case3 = min(min_case3, case3[i]);
            case4[i] = arr1[i] - arr2[i] - i;
            max_case4 = max(max_case4, case4[i]);
            min_case4 = min(min_case4, case4[i]);
        }
        return max({max_case1 - min_case1, max_case2 - min_case2, max_case3 - min_case3, max_case4 - min_case4});
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr1 = {1, 2, 3, 4};
    vector<int> given_arr2 = {-1, 4, 5 ,6};
    int expected_answer = 13;
    assert(solution.maxAbsValExpr(given_arr1, given_arr2) == expected_answer);

    given_arr1 = {1, -2, -5, 0, 10};
    given_arr2 = {0, -2, -1, -7, -4};
    expected_answer = 20;
    assert(solution.maxAbsValExpr(given_arr1, given_arr2) == expected_answer);

    return 0;
}
