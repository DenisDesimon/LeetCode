//#3918 Sum of Primes Between Number and Its Reverse - https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
private:
    bool isPrime(int num)
    {
        if(num == 1)
            return false;
        for(int i = 2; i * i <= num; i++)
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    int reverse(int num)
    {
        int result = 0;
        while(num)
        {
            result *= 10;
            result += num % 10;
            num /= 10;
        }
        return result;
    }
public:
    int sumOfPrimesInRange(int n) {
        int reversed = reverse(n);
        int left = min(reversed, n);
        int right = max(reversed, n);
        int result = 0;
        for(; left <= right; left++)
        {
            if(isPrime(left))
                result += left;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 13;
    int expectedAnswer = 132;
    assert(solution.sumOfPrimesInRange(givenN) == expectedAnswer);

    givenN = 10;
    expectedAnswer = 17;
    assert(solution.sumOfPrimesInRange(givenN) == expectedAnswer);

    return 0;
}
