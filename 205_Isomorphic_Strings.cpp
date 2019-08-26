//#205 Isomorphic Strings - https://leetcode.com/problems/isomorphic-strings/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_s;
        unordered_map<char, char> hash_t;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(hash_s.count(s[i]))
            {
                if(hash_s[s[i]] != t[i])
                    return false;
            }
            else
                hash_s[s[i]] = t[i];
            if(hash_t.count(t[i]))
            {
                if(hash_t[t[i]] != s[i])
                    return false;
            }
            else
                hash_t[t[i]] = s[i];
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string given_s = "egg", given_t = "add";
    bool expected_answer = true;
    assert(solution.isIsomorphic(given_s, given_t) == expected_answer);

    given_s = "foo", given_t = "bar";
    expected_answer = false;
    assert(solution.isIsomorphic(given_s, given_t) == expected_answer);

    return 0;
}
