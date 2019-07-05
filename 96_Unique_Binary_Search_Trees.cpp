//#96 Unique Binary Search Trees - https://leetcode.com/problems/unique-binary-search-trees/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[max(3, n + 1)];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int tree_size = 3; tree_size <= n; tree_size++)
        {
            int sub_sum = 0;
            for(int root = 1; root <= tree_size; root++)
            {
                int num_of_right_subtrees = dp[root - 1];
                int num_of_left_subtrees = dp[tree_size - root];
                sub_sum += num_of_left_subtrees * num_of_right_subtrees;
            }
            dp[tree_size] = sub_sum;
        }
        return dp[n];

    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    int expected_answer = 5;
    assert(solution.numTrees(given_n) == expected_answer);

    given_n = 5;
    expected_answer = 42;
    assert(solution.numTrees(given_n) == expected_answer);

    return 0;
}
