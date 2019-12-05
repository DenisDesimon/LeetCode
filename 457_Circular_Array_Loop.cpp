//#457 Circular Array Loop - https://leetcode.com/problems/circular-array-loop/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int swap;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 1001)
                continue;
            int j = abs(i + n + nums[i] % n) % n;
            bool flag = nums[i] > 0;
            nums[i] = 1001 + i;
            int length = 1;
            while(true)
            {
                if(nums[j] == 1001 + i && length > 1)
                    return true;
                if(nums[j] >= 1001)
                    break;
                if((nums[j] > 0) ^ flag)
                    break;
                swap = j;
                length++;
                j = abs(j + n + nums[j] % n) % n;
                nums[swap] = 1001 + i;
                if(j == swap)
                    break;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-1, -1, -3};
    bool expected_answer = false;
    assert(solution.circularArrayLoop(given_nums) == expected_answer);

    given_nums = {2, -1, 1, 2, 2};
    expected_answer = true;
    assert(solution.circularArrayLoop(given_nums) == expected_answer);

    return 0;
}
