//#1130 Minimum Cost Tree From Leaf Values - https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> nodes;
        int result = 0;
        nodes.push_back(INT_MAX);
        for(auto node : arr)
        {
            while(nodes.back() < node)
            {
                int cur_node = nodes.back();
                nodes.pop_back();
                result += cur_node * min(nodes.back(), node);
            }
            nodes.push_back(node);
        }
        for(int i = 2; i < (int)nodes.size(); i++)
            result += nodes[i] * nodes[i - 1];
        return result;

    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {10, 8, 3, 2, 5, 7, 4, 9};
    int expected_answer = 302;
    assert(solution.mctFromLeafValues(given_arr) == expected_answer);

    given_arr = {6, 2, 4};
    expected_answer = 32;
    assert(solution.mctFromLeafValues(given_arr) == expected_answer);

    return 0;
}
