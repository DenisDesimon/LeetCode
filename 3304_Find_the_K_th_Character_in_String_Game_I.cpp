//#3304 Find the K-th Character in String Game I - https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        int shifts = 0;
        int half;
        while(k != 1)
        {
            half = __lg(k);
            if(k == (1 << half))
                half--;
            k -= 1 << half;
            shifts++;
        }
        return 'a' + shifts;
    }
};

int main()
{
    Solution solution;
    int given_k = 10;
    char expected_answer = 'c';
    assert(solution.kthCharacter(given_k) == expected_answer);

    given_k = 5;
    expected_answer = 'b';
    assert(solution.kthCharacter(given_k) == expected_answer);

    return 0;
}
