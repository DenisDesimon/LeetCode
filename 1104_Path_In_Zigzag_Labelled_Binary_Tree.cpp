//#1104 Path In Zigzag Labelled Binary Tree - https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int next_power_of_two(int n){
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
        return n;
    }
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.insert(result.begin(), label);
        while(label != 1)
        {
            label /= 2;
            int max_val = next_power_of_two(label + 1) - 1;
            int min_val = (max_val + 1) / 2;
            result.insert(result.begin(), abs(max_val - label + min_val));
            if(label != 1)
            {
                label /= 2;
                result.insert(result.begin(), label);
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    int given_label = 14;
    vector<int> expected_answer = {1, 3, 4, 14};
    assert(solution.pathInZigZagTree(given_label) == expected_answer);

    given_label = 26;
    expected_answer = {1, 2, 6, 10, 26};
    assert(solution.pathInZigZagTree(given_label) == expected_answer);

    return 0;
}
