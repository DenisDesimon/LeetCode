//#373 Find K Pairs with Smallest Sums - https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> queue;
        vector<vector<int>> result;
        int n = nums1.size();
        int m = nums2.size();
        k = min(k, n * m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                queue.push({-nums1[i] - nums2[j], {nums1[i], nums2[j]}});
            }
        }
        while(!queue.empty() && k)
        {
            result.push_back(queue.top().second);
            queue.pop();
            k--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {1, 2, 4, 5, 6};
    vector<int> given_nums2 = {3, 5, 7, 9};
    int given_k = 3;
    vector<vector<int>> expected_answer = {{1, 3}, {2, 3}, {1, 5}};
    assert(solution.kSmallestPairs(given_nums1, given_nums2, given_k) == expected_answer);

    given_nums1 = {1, 7, 11};
    given_nums2 = {2, 4, 6};
    given_k = 3;
    expected_answer = {{1, 2}, {1, 4}, {1, 6}};
    assert(solution.kSmallestPairs(given_nums1, given_nums2, given_k) == expected_answer);

    return 0;
}
