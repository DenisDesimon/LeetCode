//#451 Sort Characters By Frequency - https://leetcode.com/problems/sort-characters-by-frequency/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        if(s.empty())
            return s;
        int alphabet[96] = {0};
        pair<int, char> pair_s[s.size()];
        for(char& ch : s)
            alphabet[ch - ' ']++;
        for(int i = 0; i < (int)s.size(); i++)
            pair_s[i] = {alphabet[s[i] - ' '], s[i]};
        sort(pair_s, pair_s + s.size(), [](pair<int, char> a, pair<int, char> b){if(a.first == b.first) return a.second > b.second; return a.first > b.first;});
        for(int i = 0; i < (int)s.size(); i++)
            s[i] = (char)pair_s[i].second;
        return s;
    }
};

int main()
{
    Solution solution;
    string given_s = "abbbaacacf";
    string expected_answer = "aaaabbbccf";
    assert(solution.frequencySort(given_s) == expected_answer);

    given_s = "Aabb";
    expected_answer = "bbaA";
    assert(solution.frequencySort(given_s) == expected_answer);

    return 0;
}
