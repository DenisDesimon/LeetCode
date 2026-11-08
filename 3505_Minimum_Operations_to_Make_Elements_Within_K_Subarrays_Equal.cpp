//#3505 Minimum Operations to Make Elements Within K Subarrays Equal - https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;

class Solution {
    vector<long long> countOperations(vector<int>& nums, int x){
        int n = nums.size();
        vector<long long> result(n);
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;
        for(int i = 0; i < n; i++)
        {
            if(left.empty() || nums[i] <= *left.rbegin())
            {
                left.insert(nums[i]);
                sumLeft += nums[i];
            }
            else
            {
                right.insert(nums[i]);
                sumRight += nums[i];
            }
            if(i >= x)
            {
                auto it = left.find(nums[i - x]);
                if(it != left.end())
                {
                    left.erase(it);
                    sumLeft -= nums[i - x];
                }
                else
                {
                    it = right.find(nums[i - x]);
                    right.erase(it);
                    sumRight -= nums[i - x];
                }
            }
            if(left.size() > right.size() + 1)
            {
                auto it = prev(left.end());
                right.insert(*it);
                sumLeft -= *it;
                sumRight += *it;
                left.erase(it);
            }
            else if(right.size() > left.size())
            {
                auto it = right.begin();
                left.insert(*it);
                sumLeft += *it;
                sumRight -= *it;
                right.erase(it);
            }
            if(i >= x - 1)
            {
                long long median = *left.rbegin();
                long long leftCount = median * left.size() - sumLeft;
                long long rightCount = sumRight - median * right.size();
                result[i] = leftCount + rightCount;
            }
        }
        return result;
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> operations = countOperations(nums, x);
        vector<long long> prev(n + 1, 0);
        vector<long long> cur(n + 1, LLONG_MAX);
        for(int j = 1; j <= k; j++)
        {
            fill(cur.begin(), cur.end(), LLONG_MAX);
            for(int i = j * x; i <= n; i++)
            {
                cur[i] = min(cur[i - 1], operations[i - 1] + prev[i - x]);
            }
            prev.swap(cur);
        }
        return prev[n];
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, -2, 1, 3, 7, 3, 6, 4, -1};
    int givenX = 3;
    int givenK = 2;
    long long expectedAnswer = 8;
    assert(solution.minOperations(givenNums, givenX, givenK) == expectedAnswer);

    givenNums = {9, -2, -2, -2, 1, 5};
    givenX = 2;
    givenK = 2;
    expectedAnswer = 3;
    assert(solution.minOperations(givenNums, givenX, givenK) == expectedAnswer);

    return 0;
}
