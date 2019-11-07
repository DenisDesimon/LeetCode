//#762 Prime Number of Set Bits in Binary Representation - https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
    bool is_prime(int num){
        return num == 2 || num == 3 || num == 5 || num == 7  || num == 11 || num == 13 || num == 17 || num == 19
                || num == 23 || num == 29;
    }
public:
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        for(int i = L; i <= R; i++)
        {
            if(is_prime(__builtin_popcount(i)))
                result++;

        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_L = 6;
    int given_R = 10;
    int expected_answer = 4;
    assert(solution.countPrimeSetBits(given_L, given_R) == expected_answer);

    given_L = 10;
    given_R = 15;
    expected_answer = 5;
    assert(solution.countPrimeSetBits(given_L, given_R) == expected_answer);

    return 0;
}
