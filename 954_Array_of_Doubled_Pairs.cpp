//#954 Array of Doubled Pairs - https://leetcode.com/problems/array-of-doubled-pairs/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> hash;
        for(auto num : A)
        {
            hash[abs(num)]++;
        }
        for(auto pair : hash)
        {
            if(pair.second == 0)
                continue;
            if(pair.second > hash[pair.first * 2])
                return false;
            hash[pair.first * 2] -= pair.second;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {-1, 2, 4, 2, 4, 2, -2, 4};
    bool expected_answer = true;
    assert(solution.canReorderDoubled(given_A) == expected_answer);

    given_A = {2, 1, 2, 6};
    expected_answer = false;
    assert(solution.canReorderDoubled(given_A) == expected_answer);

    return 0;
}
