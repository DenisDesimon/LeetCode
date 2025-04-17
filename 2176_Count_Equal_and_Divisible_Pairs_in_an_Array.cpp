//#2176 Count Equal and Divisible Pairs in an Array - https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexPairs;
        int result = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            if(indexPairs.count(nums[i]))
            {
                for(auto &index : indexPairs[nums[i]]){
                    if(index * i % k == 0)
                        result++;
                }
            }
            indexPairs[nums[i]].push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 1, 2, 2, 2, 1, 3};
    int given_k = 2;
    int expected_answer = 4;
    assert(solution.countPairs(given_nums, given_k) == expected_answer);

    given_nums = {1, 2, 3, 4};
    given_k = 1;
    expected_answer = 0;
    assert(solution.countPairs(given_nums, given_k) == expected_answer);

    return 0;
}
