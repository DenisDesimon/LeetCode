//#3510 Minimum Pair Removal to Sort Array II - https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
       int n = nums.size();
       if(n <= 1)
           return 0;
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> sumLeft;
       int sorted = 0;
       vector<long long> numsMod(nums.begin(), nums.end());
       for(int i = 1; i < n; i++)
       {
           sumLeft.emplace(nums[i] + nums[i - 1], i - 1);
           if(nums[i] >= nums[i - 1])
               sorted++;
       }
       if(sorted == n - 1)
           return 0;

       vector<int> prev(n), next(n);
       vector<bool> isRemoved(n);
       for(int i = 0; i < n; i++)
       {
           prev[i] = i - 1;
           next[i] = i + 1;
       }

       int numLeft = n;
       while(numLeft > 1)
       {
           long long sum = sumLeft.top().first;
           int left = sumLeft.top().second;
           sumLeft.pop();
           int right = next[left];
           if(right >= n || isRemoved[right] || isRemoved[left] || sum != numsMod[left] + numsMod[right])
               continue;

            int leftMost = prev[left];
            int rightMost = next[right];
            if(leftMost != -1 && numsMod[leftMost] <= numsMod[left])
                sorted--;
            if(numsMod[left] <= numsMod[right])
                sorted--;
            if(rightMost != n && numsMod[right] <= numsMod[rightMost])
                sorted--;

            numsMod[left] += numsMod[right];
            isRemoved[right] = true;
            numLeft--;

            if(leftMost != -1)
            {
                sumLeft.emplace(numsMod[leftMost] + numsMod[left], leftMost);
                if(numsMod[leftMost] <= numsMod[left])
                    sorted++;
            }

            if(rightMost == n)
            {
                next[left] = n;
            }
            else
            {
                next[left] = rightMost;
                prev[rightMost] = left;
                sumLeft.emplace(numsMod[left] + numsMod[rightMost], left);
                if(numsMod[left] <= numsMod[rightMost])
                    sorted++;
            }

            if(sorted == numLeft - 1)
                return n - numLeft;

       }
       return n - numLeft;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {5, 2, 3, 1};
    int expectedAnswer = 2;
    assert(solution.minimumPairRemoval(givenNums) == expectedAnswer);

    givenNums = {1, 2, 2};
    expectedAnswer = 0;
    assert(solution.minimumPairRemoval(givenNums) == expectedAnswer);

    return 0;
}
