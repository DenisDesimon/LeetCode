//#216 Combination Sum III - https://leetcode.com/problems/combination-sum-iii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n, int start = 1) {
        if(n < 1 || n < start)
            return {};
        if(k == 1 && n > 9)
            return {};
        else if(k == 1)
            return {{n}};
        vector<vector<int>> result;
        for(int i = start; (i * k) + k - 1 <= n; i++)
        {
            vector<vector<int>> sub_result = combinationSum3(k - 1, n - i, i + 1);
            if(sub_result.empty())
                continue;
            for(auto &res : sub_result)
            {
                res.insert(res.begin(), i);
                result.push_back(res);
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_k = 3;
    int given_n = 9;
    vector<vector<int>> expected_answer = {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}};
    assert(solution.combinationSum3(given_k, given_n) == expected_answer);

    given_k = 3;
    given_n = 7;
    expected_answer = {{1, 2, 4}};
    assert(solution.combinationSum3(given_k, given_n) == expected_answer);

    return 0;
}
