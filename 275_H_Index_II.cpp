//#275 H-Index II - https://leetcode.com/problems/h-index-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if((int)citations.size() == 1)
            return min(citations[0], 1);
        int result = 0, n = citations.size();
        for(int i = n / 2; i >= 1; i /= 2)
        {
            while(result + i <= n && citations[n - (i + result)] >= (i + result))
                result += i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_citations = {0, 1, 3, 5, 6};
    int expected_answer = 3;
    assert(solution.hIndex(given_citations) == expected_answer);

    given_citations = {1};
    expected_answer = 1;
    assert(solution.hIndex(given_citations) == expected_answer);

    return 0;
}
