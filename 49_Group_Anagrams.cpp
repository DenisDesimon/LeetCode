//#49 Group Anagrams - https://leetcode.com/problems/group-anagrams/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> result;
        for(auto anagram : strs)
        {
            string key = anagram;
            sort(key.begin(), key.end());
            hash[key].push_back(anagram);
        }
        for(auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            result.push_back((*iter).second);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> expected_answer = {{"bat"}, {"eat", "tea", "ate"}, {"tan", "nat"}};
    assert(solution.groupAnagrams(given_strs) == expected_answer);

    return 0;
}
