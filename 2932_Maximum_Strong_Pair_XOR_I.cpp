//#2932 Maximum Strong Pair XOR I - https://leetcode.com/problems/maximum-strong-pair-xor-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int result = 0;
        for(auto &num : nums)
        {
            for(auto &num2: nums)
            {
                if(abs(num - num2) <= min(num, num2))
                    result = max(result, num ^ num2);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 4, 5};
    int expected_answer = 7;
    assert(solution.maximumStrongPairXor(given_nums) == expected_answer);

    given_nums = {5, 6, 25, 30};
    expected_answer = 7;
    assert(solution.maximumStrongPairXor(given_nums) == expected_answer);

    return 0;
}
