//#1342 Reduce Array Size to The Half - https://leetcode.com/problems/reduce-array-size-to-the-half/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int result = 0;
        unordered_map<int, int> hash;
        for(auto& item : arr)
            hash[item]++;
        int dest = (arr.size() % 2) == 0 ? arr.size() / 2 : arr.size() / 2 + 1;
        multiset<int> sorted_hash;
        for(auto& item : hash)
            sorted_hash.insert(item.second);
        auto iter = sorted_hash.rbegin();
        while(dest > 0)
        {
            result++;
            dest -= *iter;
            iter++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {9, 77, 63, 22, 92, 9, 14, 54, 8, 38, 18, 19, 38, 68, 58, 19};
    int expected_answer = 5;
    assert(solution.minSetSize(given_arr) == expected_answer);

    given_arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    expected_answer = 2;
    assert(solution.minSetSize(given_arr) == expected_answer);

    return 0;
}
