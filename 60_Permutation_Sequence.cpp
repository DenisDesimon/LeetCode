//#60 Permutation Sequence - https://leetcode.com/problems/permutation-sequence/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> nums;
        int fact = 1;
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        k--;
        for(int i = 0; i < n; i++)
        {
            fact /= (n - i);
            result += nums[k / fact] + '0';
            nums.erase(nums.begin() + k / fact);
            k %= fact;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 3, given_k = 3;
    string expected_answer = "213";
    assert(solution.getPermutation(given_n, given_k) == expected_answer);

    given_n = 4, given_k = 9;
    expected_answer = "2314";
    assert(solution.getPermutation(given_n, given_k) == expected_answer);

    return 0;
}
