//#3886 Sum of Sortable Integers - https://leetcode.com/problems/sum-of-sortable-integers/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    bool check(vector<int> &nums, vector<int> &target){
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                vector<int> rotated;
                rotated.insert(rotated.end(), nums.begin() + i + 1, nums.end());
                rotated.insert(rotated.end(), nums.begin(), nums.begin() + i + 1);
                return rotated == target;
            }
        }
        return nums == target;
    }
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> factors;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                factors.push_back(i);
                if(n / i != i)
                    factors.push_back(n / i);
            }
        }
        vector<int> target = nums;
        sort(target.begin(), target.end());
        int result = 0;
        for(auto &factor: factors)
        {
            int left = 0;
            for(; left < n; left += factor)
            {
                int right = left + factor;
                vector<int> curSub = vector<int>(nums.begin() + left, nums.begin() + right);
                vector<int> targetSub = vector<int>(target.begin() + left, target.begin() + right);
                if(!check(curSub, targetSub))
                    break;
            }
            if(left >= n)
                result += factor;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {3, 1, 2};
    int expectedAnswer = 3;
    assert(solution.sortableIntegers(givenNums) == expectedAnswer);

    givenNums  = {5, 8};
    expectedAnswer = 3;
    assert(solution.sortableIntegers(givenNums) == expectedAnswer);

    return 0;
}
