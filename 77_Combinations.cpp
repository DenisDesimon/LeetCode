//#77 Combinations - https://leetcode.com/problems/combinations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int size = 1 << n;
        vector<vector<int>> result;
        for(int i = 1; i < size; i++)
        {
            if(__builtin_popcount(i) == k)
            {
                vector<int> sub_result;
                for(int j = 0; j < n; j++)
                {
                    if(i & (1 << j))
                        sub_result.push_back(j + 1);
                }
                result.push_back(sub_result);
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    int given_n = 4;
    int given_k = 2;
    vector<vector<int>> expected_answer = {{1, 2}, {1, 3}, {2, 3}, {1, 4}, {2, 4}, {3, 4}};
    assert(solution.combine(given_n, given_k) == expected_answer);

    given_n = 2;
    given_k = 2;
    expected_answer = {{1, 2}};
    assert(solution.combine(given_n, given_k) == expected_answer);

    return 0;
}
