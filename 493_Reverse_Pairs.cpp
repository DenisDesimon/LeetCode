//#493 Reverse Pairs - https://leetcode.com/problems/reverse-pairs/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> tree;
    int sum(int index){
        int sum = 0;
        while(index < (int)tree.size())
        {
            sum += tree[index];
            index += index & (-index);
        }
        return sum;
    }
    void update(int index){
        while(index > 0)
        {
            tree[index] += 1;
            index -= index & (-index);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), result = 0;
        vector<int> nums_sort(nums);
        tree.resize(n + 1, 0);
        sort(nums_sort.begin(), nums_sort.end());
        for(int i = 0; i < n; i++)
        {
        result += sum(lower_bound(nums_sort.begin(), nums_sort.end(), nums[i] * 2LL + 1) - nums_sort.begin() + 1);
        update(lower_bound(nums_sort.begin(), nums_sort.end(), nums[i]) - nums_sort.begin() + 1);
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 2, 3, 1};
    int  expected_answer = 2;
    assert(solution.reversePairs(given_nums) == expected_answer);

    given_nums = {1, 110, 2, 114, 3, 112, 4, 115, 5, 111, 113, 1, 1, 1, 1, 1};
    expected_answer = 55;
    assert(solution.reversePairs(given_nums) == expected_answer);

    return 0;
}
