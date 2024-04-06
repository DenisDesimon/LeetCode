//#3066 Minimum Operations to Exceed Threshold Value II - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long int>, greater<long long int>> pq;
        int result = 0;
        for(auto &num : nums){
            pq.push(num);
        }
        while(pq.top() < k)
        {
            long long left = pq.top();
            pq.pop();
            long long right = pq.top();
            pq.pop();
            pq.push(left * 2 + right);
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 1, 2, 4, 9};
    int given_k = 20;
    int expected_answer = 4;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    given_nums = {2, 11, 10, 1, 3};
    given_k = 10;
    expected_answer = 2;
    assert(solution.minOperations(given_nums, given_k) == expected_answer);

    return 0;
}
