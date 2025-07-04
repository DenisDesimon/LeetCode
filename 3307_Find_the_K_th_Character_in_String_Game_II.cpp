//#3307 Find the K-th Character in String Game II - https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long shifts = 0;
        long long mid;
        while(k != 1)
        {
            mid = __lg(k);
            if(k == (1LL << mid))
                mid--;
            k = k - (1LL << mid);
            shifts += operations[mid];
        }
        return 'a' + (shifts % 26);
    }
};

int main()
{
    Solution solution;
    int given_k = 10;
    vector<int> given_operations = {0, 0, 0, 1};
    char expected_answer = 'b';
    assert(solution.kthCharacter(given_k, given_operations) == expected_answer);

    given_k = 5;
    given_operations = {0, 0, 0};
    expected_answer = 'a';
    assert(solution.kthCharacter(given_k, given_operations) == expected_answer);

    return 0;
}


