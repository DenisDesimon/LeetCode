//#989 Add to Array-Form of Integer - https://leetcode.com/problems/add-to-array-form-of-integer/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int overcome = 0;
        for(int i = A.size() - 1; i >= 0; i--)
        {
            int digit = K % 10 + overcome + A[i];
            A[i] = digit % 10;
            overcome = digit / 10;
            K /= 10;
        }
        while(K || overcome)
        {
            int digit = K % 10 + overcome;
            A.insert(A.begin(), digit % 10);
            K /= 10;
            overcome = digit / 10;
        }
        return A;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {7};
    int given_K = 993;
    vector<int> expected_answer = {1, 0, 0, 0};
    assert(solution.addToArrayForm(given_A, given_K) == expected_answer);

    given_A = {1, 2, 0, 0};
    given_K = 34;
    expected_answer = {1, 2, 3, 4};
    assert(solution.addToArrayForm(given_A, given_K) == expected_answer);

    return 0;
}
