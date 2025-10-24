//#2048 Next Greater Numerically Balanced Number - https://leetcode.com/problems/next-greater-numerically-balanced-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
    bool isBeutiful(int num){
        int count[10] = {0};
        while(num)
        {
            count[num % 10]++;
            num /= 10;
        }
        for(int i = 0; i < 10; i++)
        {
            if(count[i] && count[i] != i)
                return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int i = n + 1; i <= 1224444; i++)
        {
            if(isBeutiful(i))
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int givenN = 1000;
    int expectedAnswer = 1333;
    assert(solution.nextBeautifulNumber(givenN) == expectedAnswer);

    givenN = 3000;
    expectedAnswer = 3133;
    assert(solution.nextBeautifulNumber(givenN) == expectedAnswer);

    return 0;
}
