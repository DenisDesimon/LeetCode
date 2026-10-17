//#3551 Minimum Swaps to Sort by Digit Sum - https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
#include <iostream>
#include <cassert>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    int find(int cur, vector<int> &parents){
        if(parents[cur] == -1)
            return cur;
        return find(parents[cur], parents);
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSums(n);
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            while(num)
            {
                digitSums[i] += num % 10;
                num /= 10;
            }
        }
        vector<int> sortedIdx(n);
        iota(sortedIdx.begin(), sortedIdx.end(), 0);
        sort(sortedIdx.begin(), sortedIdx.end(), [&](int &left, int &right) {
            if(digitSums[left] != digitSums[right])
                return digitSums[left] < digitSums[right];
            return nums[left] < nums[right];
        });
        vector<int> targetIdx(n);
        for(int i = 0; i < n; i++)
            targetIdx[sortedIdx[i]] = i;
        vector<int> parents(n, -1);
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int left = find(i, parents);
            int right = find(targetIdx[i], parents);
            if(left != right)
            {
                result++;
                parents[left] = right;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {37, 100};
    int expectedAnswer = 1;
    assert(solution.minSwaps(givenNums) == expectedAnswer);

    givenNums  = {18, 43, 34, 16};
    expectedAnswer = 2;
    assert(solution.minSwaps(givenNums) == expectedAnswer);

    return 0;
}
