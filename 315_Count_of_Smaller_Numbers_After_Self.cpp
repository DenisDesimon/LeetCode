//#315 Count of Smaller Numbers After Self - https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct BinaryIndexTree{
    int n;
    vector<int> bit;
    BinaryIndexTree(){
        n = 2 * 10000 + 2;
        bit.assign(n, 0);
    }
    void update(int num, int delta){
        while(num < n){
            bit[num] += delta;
            num += num & (-num);
        }
    }
    int getCount(int num){
        int res = 0;
        while(num > 0){
            res += bit[num];
            num -= num & (-num);
        }
        return res;
    }
};

class Solution {
    int getPositive(int num){
        return num + 10001;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        BinaryIndexTree bit;
        for(auto & num : nums)
            bit.update(getPositive(num), 1);
        for(auto & num : nums)
        {
            result.push_back(bit.getCount(getPositive(num - 1)));
            bit.update(getPositive(num), -1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 2, 6, 1};
    vector<int> expected_answer = {2, 1, 1, 0};
    assert(solution.countSmaller(given_nums) == expected_answer);

    given_nums = {-1, 0};
    expected_answer = {0, 0};
    assert(solution.countSmaller(given_nums) == expected_answer);

    return 0;
}
