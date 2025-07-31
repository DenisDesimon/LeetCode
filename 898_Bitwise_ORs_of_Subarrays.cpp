//#898 Bitwise ORs of Subarrays - https://leetcode.com/problems/bitwise-ors-of-subarrays/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        vector<int> previous;
        for(auto &num : arr)
        {
            vector<int> cur;
            cur.push_back(num);
            for(auto &prev : previous)
            {
                if(cur.back() != (prev | num))
                    cur.push_back(prev | num);
            }
            previous = cur;
            result.insert(cur.begin(), cur.end());
        }
        return result.size();
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr = {1, 2, 4};
    int expectedAnswer = 6;
    assert(solution.subarrayBitwiseORs(givenArr) == expectedAnswer);

    givenArr = {1, 1, 4};
    expectedAnswer = 3;
    assert(solution.subarrayBitwiseORs(givenArr) == expectedAnswer);

    return 0;
}
