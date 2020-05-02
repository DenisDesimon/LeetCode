//#771 Jewels and Stones - https://leetcode.com/problems/jewels-and-stones/
#include <iostream>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels;
        int result = 0;
        for(auto& jewel : J)
            jewels.insert(jewel);
        for(auto& stone : S)
        {
            if(jewels.count(stone))
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_jewels = "aA";
    string given_stones = "aAAbbbb";
    int expected_answer = 3;
    assert(solution.numJewelsInStones(given_jewels, given_stones) == expected_answer);

    given_jewels = "aA";
    given_stones = "ZZ";
    expected_answer = 0;
    assert(solution.numJewelsInStones(given_jewels, given_stones) == expected_answer);

    return 0;
}
