//#2917 Find the K-or of an Array - https://leetcode.com/problems/find-the-k-or-of-an-array/description/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int result = 0;
        for(int i = 0; i < 32; i++)
        {
            int count = 0;
            for(auto num : nums)
            {
                if(num & (1 << i))
                    count++;
            }
            if(count >= k)
                result += (1 << i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {7, 12, 9, 8, 9, 15};
    int given_k = 4;
    int expected_answer = 9;
    assert(solution.findKOr(given_nums, given_k) == expected_answer);

    given_nums = {2, 12, 1, 11, 4, 5};
    given_k = 6;
    expected_answer = 0;
    assert(solution.findKOr(given_nums, given_k) == expected_answer);

    return 0;
}
