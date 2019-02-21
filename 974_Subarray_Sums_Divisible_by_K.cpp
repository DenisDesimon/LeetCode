//#974 Subarray Sums Divisible by K - https://leetcode.com/problems/subarray-sums-divisible-by-k/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
//P[i+1] = A[0] + A[1] + ... + A[i](PrefixSum)
        vector<int> PrefixSums(A.size() + 1, 0);
        for(int i = 0; i < (int)A.size() ; i++)
        {
            PrefixSums[i + 1] = PrefixSums[i] + A[i];
        }
//Then, each subarray can be written as P[j] - P[i](subtraction of 2 PrefixSums)
//Thus, we have P[j] - P[i] equal to 0 modulo K, or equivalently P[i] and P[j] are the same value modulo K.
        vector<int> CountMod(K, 0);
        for(auto PrefixSum : PrefixSums)
        {
            CountMod[(PrefixSum % K + K) % K] ++ ;
        }
        int result = 0;
//To count all possible subarrays, we need to count a sum of the number of 2-combinations from a set CountMod
//The number of 2-combinations from a set CountMod, C(CountMod, 2) = CountMod!/(CountMod - 2)! * 2! = CountMod * (CountMod - 1) / 2
        for(auto Mod : CountMod)
        {
            result += Mod * (Mod - 1) / 2;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 5, 0, -2, -3, 1};
    int given_K = 5;
    int  expected_answer = 7;
    assert(solution.subarraysDivByK(given_nums, given_K) == expected_answer);

    return 0;
}
