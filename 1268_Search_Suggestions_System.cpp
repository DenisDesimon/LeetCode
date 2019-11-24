//#1268 Search Suggestions System - https://leetcode.com/problems/search-suggestions-system/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());
        for(int i = 0; i < (int)searchWord.size(); i++)
        {
            string word = searchWord.substr(0, i + 1);
            auto iter_start = lower_bound(products.begin(), products.end(), word);
            auto iter_end = lower_bound(iter_start, min(iter_start + 3, products.end()), searchWord.substr(0, i) + (char)(searchWord[i] + 1));
            result.push_back(vector<string>(iter_start, iter_end));
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<string> given_products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string given_search = "mouse";
    vector<vector<string>> expected_answer = {{"mobile", "moneypot", "monitor"},
                                              {"mobile", "moneypot", "monitor"},
                                              {"mouse", "mousepad"},
                                              {"mouse", "mousepad"},
                                              {"mouse", "mousepad"}};
    assert(solution.suggestedProducts(given_products, given_search) == expected_answer);

    given_products = {"havana"};
    given_search = "tatiana";
    expected_answer = {{}, {}, {}, {}, {}, {}, {}};
    assert(solution.suggestedProducts(given_products, given_search) == expected_answer);

    return 0;
}
