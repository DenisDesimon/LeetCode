//#3890 Integers With Multiple Sum of Two Cubes - https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int, int> countX;
        int lim = cbrt(n);
        for(int a = 1; a <= lim; a++)
        {
            for(int b = a; b <= lim; b++)
            {
                int x = a * a * a + b * b * b;
                if(x > n)
                    break;
                countX[x]++;
            }
        }
        vector<int> result;
        for(auto &count : countX)
        {
            if(count.second > 1)
                result.push_back(count.first);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 4104;
    vector<int> expectedAnswer = {1729, 4104};
    assert(solution.findGoodIntegers(givenN) == expectedAnswer);

    givenN = 578;
    expectedAnswer = {};
    assert(solution.findGoodIntegers(givenN) == expectedAnswer);

    return 0;
}
