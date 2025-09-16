//#2197 Replace Non-Coprime Numbers in Array  - https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int getGcd(int left, int right){
        while(left % right)
        {
            int temp = right;
            right = left % right;
            left = temp;
        }
        return right;
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result;
        for(auto &num : nums)
        {
            while(true)
            {
                int divisor = getGcd(result.empty() ? 1 : result.back(), num);
                if(divisor == 1)
                    break;
                num = result.back() * num / divisor;
                result.pop_back();
            }
            result.push_back(num);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums  = {6, 4, 3, 2, 7, 6, 2};
    vector<int> expectedAnswer = {12, 7, 6};
    assert(solution.replaceNonCoprimes(givenNums) == expectedAnswer);

    givenNums = {2009, 899, 20677, 825};
    expectedAnswer = {2009, 20677 ,825};
    assert(solution.replaceNonCoprimes(givenNums) == expectedAnswer);

    return 0;
}
