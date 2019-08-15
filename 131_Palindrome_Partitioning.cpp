//#131 Palindrome Partitioning - https://leetcode.com/problems/palindrome-partitioning/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool is_palin(string& str){
        int left = 0, right = str.size() - 1;
        while(left < right)
        {
            if(str[left++] != str[right--])
                return false;
        }
        return true;
    }
    void generate(int idx, string& s, vector<vector<string>>& result, vector<string>& cur_part){
        if(idx == (int)s.size())
        {
            result.push_back(cur_part);
            return;
        }
        string temp;
        for(; idx < (int)s.size(); idx++)
        {
            temp += s[idx];
            if(is_palin(temp))
            {
                cur_part.push_back(temp);
                generate(idx + 1, s, result, cur_part);
                cur_part.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> cur_part;
        generate(0, s, result, cur_part);
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "aab";
    vector<vector<string>> expected_answer = {{"a", "a", "b"}, {"aa", "b"}};
    assert(solution.partition(given_s) == expected_answer);

    given_s = "aba";
    expected_answer = {{"a", "b", "a"}, {"aba"}};
    assert(solution.partition(given_s) == expected_answer);

    return 0;
}
