//#307 Range Sum Query - Mutable - https://leetcode.com/problems/range-sum-query-mutable/
//Using Binary Indexed Tree
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class NumArray {
    vector<int> tree;
    int sum(int k){
        int s = 0;
        while(k >= 1)
        {
            s += tree[k];
            k -= k & (-k);
        }
        return s;
    }
public:
    NumArray(vector<int> nums) {
        tree.resize(nums.size() + 1, 0);
        for(int i = (int)tree.size() - 1; i >= 1; i--)
        {
            update(i - 1, nums[i - 1]);
        }

    }

    void update(int i, int val) {
        int x = val - sumRange(i, i);
        i++;
        while(i < (int)tree.size())
        {
            tree[i] += x;
            i += i & (-i);
        }

    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }
};

int main()
{
    vector<int> given_nums = {1, 3, 5};
    NumArray solution(given_nums);
    int  expected_answer = 9;
    assert(solution.sumRange(0, 2) == expected_answer);

    solution.update(1, 2);
    expected_answer = 8;
    assert(solution.sumRange(0, 2) == expected_answer);

    return 0;
}
