//#413 Arithmetic Slices - https://leetcode.com/problems/arithmetic-slices/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        if(A.empty())
            return result;
        int last = 0;
        for(int i = 2; i < (int)A.size(); i++)
        {
            if(A[i - 1] - A[i - 2] == A[i] - A[i - 1])
                last += + 1;
            else
                last = 0;
            result += last;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {1, 2, 3, 4};
    int expected_answer = 3;
    assert(solution.numberOfArithmeticSlices(given_A) == expected_answer);

    given_A = {4, -1, -5, -9};
    expected_answer = 1;
    assert(solution.numberOfArithmeticSlices(given_A) == expected_answer);

    return 0;
}
