//#179 Largest Number - https://leetcode.com/problems/largest-number/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstring;
        string result;
        for(auto& num : nums)
            numstring.push_back(to_string(num));
        sort(numstring.begin(), numstring.end(), [](string a, string b){return (a + b) > (b + a);});
        for(auto& str : numstring)
            result += str;
        if(result[0] == '0')
            return "0";
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 346, 34, 5, 9};
    string expected_answer = "95346343";
    assert(solution.largestNumber(given_nums) == expected_answer);

    given_nums = {10, 2};
    expected_answer = "210";
    assert(solution.largestNumber(given_nums) == expected_answer);

    return 0;
}
