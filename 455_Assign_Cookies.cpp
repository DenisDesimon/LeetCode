//#455 Assign Cookies - https://leetcode.com/problems/assign-cookies/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int, int> cookies;
        int result = 0;
        for(auto cookie : s)
        {
            cookies[cookie]++;
        }
        for(auto kid : g)
        {
            auto iter = cookies.lower_bound(kid);
            while((*iter).second == 0 && iter != cookies.end())
                iter++;
            if(iter != cookies.end())
            {
                result++;
                (*iter).second--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_g = {1, 2, 3};
    vector<int> given_s = {1, 1};
    int expected_answer = 1;
    assert(solution.findContentChildren(given_g, given_s) == expected_answer);

    given_g = {1, 2, 3};
    given_s = {5, 5};
    expected_answer = 2;
    assert(solution.findContentChildren(given_g, given_s) == expected_answer);

    return 0;
}
