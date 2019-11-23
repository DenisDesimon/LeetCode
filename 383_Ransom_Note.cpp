//#383 Ransom Note - https://leetcode.com/problems/ransom-note/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        for(auto& ch : magazine)
            hash[ch]++;
        for(auto& ch : ransomNote)
        {
            if(hash[ch] <= 0)
                return false;
            hash[ch]--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string given_ransom = "a";
    string given_magazine = "b";
    bool expected_answer = false;
    assert(solution.canConstruct(given_ransom, given_magazine) == expected_answer);

    given_ransom = "aa";
    given_magazine = "aab";
    expected_answer = true;
    assert(solution.canConstruct(given_ransom, given_magazine) == expected_answer);

    return 0;
}
