//#2947 Count Beautiful Substrings I - https://leetcode.com/problems/count-beautiful-substrings-i/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<int, vector<int>> prefix;
        prefix[0].push_back(0);
        int result = 0;
        int dif = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            dif += vowels.count(s[i]) ? 1 : -1;
            prefix[dif].push_back(i + 1);
        }
        int min_div = 1;
        for(; min_div < k && min_div * min_div % k;)
            min_div++;
        min_div *= 2;
        for(auto &pref : prefix)
        {
            vector<int> count_points(min_div);
            for(auto points : pref.second)
            {
                result += count_points[points % min_div]++;
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    string given_s = "baeyh";
    int given_k = 2;
    int expected_answer = 2;
    assert(solution.beautifulSubstrings(given_s, given_k) == expected_answer);

    given_s = "abba";
    given_k = 1;
    expected_answer = 3;
    assert(solution.beautifulSubstrings(given_s, given_k) == expected_answer);

    return 0;
}
