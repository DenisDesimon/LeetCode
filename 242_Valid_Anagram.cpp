//#242 Valid Anagram - https://leetcode.com/problems/valid-anagram/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> hash;
        for(int i = 0; i < (int)s.size(); i++)
        {
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto item : hash)
        {
            if(item.second != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string given_s = "anagram";
    string given_t = "nagaram";
    bool expected_answer = true;
    assert(solution.isAnagram(given_s, given_t) == expected_answer);

    return 0;
}
