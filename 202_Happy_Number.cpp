//#202 Happy Number - https://leetcode.com/problems/happy-number/
#include <iostream>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n != 1)
        {
            int temp = 0;
            while(n)
            {
                temp += n % 10 * (n % 10);
                n /= 10;
            }
            n = temp;
            if(visited.count(n))
                return false;
            visited.insert(n);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int given_n = 25;
    bool expected_answer = false;
    assert(solution.isHappy(given_n) == expected_answer);

    given_n = 19;
    expected_answer = true;
    assert(solution.isHappy(given_n) == expected_answer);

    return 0;
}
