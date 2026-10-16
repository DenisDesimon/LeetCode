//#2916 Subarrays Distinct Element Sum of Squares II - https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class BIT{
    int size;
    vector<long long> diffTree;
    vector<long long> weightedTree;
public:
    BIT(int n){
        size = n;
        diffTree.assign(n + 2, 0);
        weightedTree.assign(n + 2, 0);
    }
    void add(int idx, int delta){
        long long startIndex = idx;
        while(idx <= size)
        {
            diffTree[idx] += delta;
            weightedTree[idx] += startIndex * delta;
            idx += idx & (-idx);
        }
    }
    long long query(int idx){
        long long startIndex = idx + 1;
        long long result = 0;
        while(idx > 0)
        {
            result += startIndex * diffTree[idx] - weightedTree[idx];
            idx -= idx & (-idx);
        }
        return result;

    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9  + 7;
        long long result = 0, cur = 0;
        BIT tree(n + 1);
        unordered_map<int, int> lastDistinct;
        for(int right = 0; right < n; right++)
        {
            int left = (lastDistinct.count(nums[right]) ? lastDistinct[nums[right]] : -1) + 1;
            long long prevDistCount = tree.query(right + 1) - tree.query(left);
            cur = (cur + prevDistCount * 2 + right - left + 1);
            result = (result + cur) % MOD;
            tree.add(left + 1, 1);
            tree.add(right + 2, -1);
            lastDistinct[nums[right]] = right;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {1, 2, 1};
    int expectedAnswer = 15;
    assert(solution.sumCounts(givenNums) == expectedAnswer);

    givenNums  = {1, 1};
    expectedAnswer = 3;
    assert(solution.sumCounts(givenNums) == expectedAnswer);

    return 0;
}
