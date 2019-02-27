//#307 Range Sum Query - Mutable - https://leetcode.com/problems/range-sum-query-mutable/
//Using Segment Tree
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class NumArray {
    vector<int> tree;
    int next_power_of_two(int n){
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
        return n;
    }
public:
    NumArray(vector<int> nums) {
        tree.resize(next_power_of_two(nums.size() * 2), 0);
        for(int i = 0; i < (int)nums.size(); i++)
            update(i, nums[i]);

    }

    void update(int i, int val) {
        i += tree.size() / 2;
        int addition = val - tree[i];
        tree[i] += addition;
        for(i /= 2; i >= 1; i /=2)
            tree[i] += addition;
    }

    int sumRange(int i, int j) {
       i += tree.size() / 2;
       j += tree.size() / 2;
       int sum = 0;
       while(i <= j)
       {
           if(i % 2 == 1)
               sum += tree[i++];
           if(j % 2 == 0)
               sum += tree[j--];
           i /= 2, j /= 2;
       }
       return sum;
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
