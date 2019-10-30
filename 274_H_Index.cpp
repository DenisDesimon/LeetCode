//#274 H-Index - https://leetcode.com/problems/h-index/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for(int i = n; i > 0; i--)
        {
            if(citations[n - i] >= i && (i == n || citations[n - i - 1] <= i))
                return i;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_citations = {3, 0, 6, 1, 5};
    int expected_answer = 3;
    assert(solution.hIndex(given_citations) == expected_answer);

    given_citations = {100};
    expected_answer = 1;
    assert(solution.hIndex(given_citations) == expected_answer);

    return 0;
}
