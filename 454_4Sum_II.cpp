//#454 4Sum II - https://leetcode.com/problems/4sum-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum_AB, sum_CD;
        int result = 0;
        for(auto& num_A : A)
        {
            for(auto& num_B : B)
            {
                sum_AB[num_A + num_B]++;
            }
        }
        for(auto& num_C : C)
        {
            for(auto& num_D : D)
            {
                sum_CD[num_C + num_D]++;
            }
        }
        for(auto& pair : sum_AB)
        {
            if(sum_CD.count(-(pair.first)))
                result += pair.second * sum_CD[-(pair.first)];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {1, 2}, given_B = {-2, -1}, given_C = {-1, 2}, given_D = {0, 2};
    int expected_answer = 2;
    assert(solution.fourSumCount(given_A, given_B, given_C, given_D) == expected_answer);

    given_A = {1}, given_B = {5}, given_C = {-7}, given_D = {1};
    expected_answer = 1;
    assert(solution.fourSumCount(given_A, given_B, given_C, given_D) == expected_answer);

    return 0;
}
