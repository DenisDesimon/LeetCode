//#17 Letter Combinations of a Phone Number - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    vector<string> phone= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void fill_result(int start, string cur_str, string digits, vector<string>& result){
        if(start == (int)digits.size())
        {
            result.push_back(cur_str);
            return;
        }
        for(auto &digit : phone[digits[start] - '0'])
        {
            cur_str.push_back(digit);
            fill_result(start + 1, cur_str, digits, result);
            cur_str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
        fill_result(0, "", digits, result);
        return result;
    }
};

int main()
{
    Solution solution;
    string given_digits = "23";
    vector<string> expected_answer = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(solution.letterCombinations(given_digits) == expected_answer);

    return 0;
}
