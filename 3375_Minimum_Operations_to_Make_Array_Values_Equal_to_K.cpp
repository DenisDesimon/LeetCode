//#3375 Minimum Operations to Make Array Values Equal to K - https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> numBehind;
        for(auto &num : nums){
            if(num < k)
                return -1;
            numBehind.insert(num);
        }
        numBehind.erase(k);
        return numBehind.size();
    }
};

int main()
{
    Solution solution;

    vector<int> given_nums = {5, 2, 5, 4, 5};
    int given_k = 2;
    int expected_answer = 2;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    given_nums = {9, 7, 5, 3};
    given_k = 1;
    expected_answer = 4;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    return 0;
}
