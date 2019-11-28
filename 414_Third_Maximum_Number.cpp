//#414 Third Maximum Number - https://leetcode.com/problems/third-maximum-number/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> hash;
        for(auto num : nums)
        {
            int start = max(0, (int)hash.size() - 3);
            auto iter = lower_bound(hash.begin() + start, hash.end(), num);
            if(iter < hash.end() && *iter == num)
                continue;
            if(iter >= hash.begin() + start)
                hash.insert(iter, num);
        }
        return hash.size() >= 3 ? hash[hash.size() - 3] : hash.back();
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 2, 5, 3, 5};
    int expected_answer = 2;
    assert(solution.thirdMax(given_nums) == expected_answer);

    given_nums = {1, 1, 2};
    expected_answer = 2;
    assert(solution.thirdMax(given_nums) == expected_answer);

    return 0;
}
