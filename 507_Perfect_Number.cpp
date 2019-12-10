//#507 Perfect Number - https://leetcode.com/problems/perfect-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0)
            return false;
        int sum = 0;
        for(int i = 1; i * i <= num; i++)
        {
            if(num % i == 0)
            {
                sum += i;
                if(i * i != num)
                    sum += num / i;
            }
        }
        return sum - num == num;
    }
};

int main()
{
    Solution solution;
    int given_num = 28;
    bool expected_answer = true;
    assert(solution.checkPerfectNumber(given_num) == expected_answer);

    given_num = 496;
    expected_answer = true;
    assert(solution.checkPerfectNumber(given_num) == expected_answer);

    return 0;
}
