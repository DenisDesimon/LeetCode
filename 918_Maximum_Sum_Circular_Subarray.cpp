//#918 Maximum Sum Circular Subarray - https://leetcode.com/problems/maximum-sum-circular-subarray/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int kadane(vector<int>& A, int start, int end, int sign){
        int result = INT_MIN;
        int cur = 0;
        for(int i = start; i <= end; i++)
        {
            cur = A[i] * sign + max(0, cur);
            result = max(result, cur);
        }
        return result;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        for(auto& num : A)
            sum += num;
        int ans1 = kadane(A, 0, A.size() - 1, 1);
        int ans2 = kadane(A, 1, A.size() - 2, -1);
        if(ans2 != INT_MIN)
            ans2 = sum + ans2;
        return  max(ans1, ans2);
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, -3 ,5};
    int expected_answer = 10;
    assert(solution.maxSubarraySumCircular(given_nums) == expected_answer);

    given_nums = {3, -1, 2, -1};
    expected_answer = 4;
    assert(solution.maxSubarraySumCircular(given_nums) == expected_answer);

    return 0;
}
