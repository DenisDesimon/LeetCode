//#3691 Maximum Total Subarray Value II - https://leetcode.com/problems/maximum-total-subarray-value-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

class SegTree{
    vector<int> maxVal, minVal;
    int n;
public:
    SegTree(vector<int> &nums){
        n = nums.size();
        maxVal.resize(n * 4);
        minVal.resize(n * 4);
        build(1, 0, n - 1, nums);
    }
    void build(int cur, int l, int r, vector<int> &nums){
        if(l == r)
        {
            maxVal[cur] = minVal[cur] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        build(cur << 1, l, mid, nums);
        build(cur << 1 | 1, mid + 1, r, nums);
        maxVal[cur] = max(maxVal[cur << 1], maxVal[cur << 1 | 1]);
        minVal[cur] = min(minVal[cur << 1], minVal[cur << 1 | 1]);
    }
    int queryMax(int cur, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr)
            return maxVal[cur];
        int mid = (l + r) / 2;
        int result = INT_MIN;
        if(ql <= mid)
            result = queryMax(cur << 1, l, mid, ql, qr);
        if(qr > mid)
            result = max(result, queryMax(cur << 1 | 1, mid + 1, r, ql, qr));
        return result;
    }
    int queryMin(int cur, int l, int r, int ql, int qr){
        if(ql <= l && r <= qr)
            return minVal[cur];
        int mid = (l + r) / 2;
        int result = INT_MAX;
        if(ql <= mid)
            result = queryMin(cur << 1, l, mid, ql, qr);
        if(qr > mid)
            result = min(result, queryMin(cur << 1 | 1, mid + 1, r, ql, qr));
        return result;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        priority_queue<pair<int, pair<int, int>>> diffSegment;
        int n = nums.size();
        SegTree tree(nums);
        for(int l = 0; l < n; l++)
        {
            diffSegment.push({tree.queryMax(1, 0, n - 1, l, n -1) - tree.queryMin(1, 0, n - 1, l, n -1), {l, n - 1}});
        }
        long long result = 0;
        while(k--)
        {
            int diff = diffSegment.top().first;
            int l = diffSegment.top().second.first;
            int r = diffSegment.top().second.second;
            diffSegment.pop();
            result += diff;
            if(r > l)
            {
                diffSegment.push({tree.queryMax(1, 0, n - 1, l, r - 1) - tree.queryMin(1, 0, n - 1, l, r - 1), {l, r - 1}});
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 2};
    int givenK = 2;
    long long expectedAnswer = 4;
    assert(solution.maxTotalValue(givenNums, givenK) == expectedAnswer);

    givenNums = {4, 2, 5, 1};
    givenK = 3;
    expectedAnswer = 12;
    assert(solution.maxTotalValue(givenNums, givenK) == expectedAnswer);

    return 0;
}
