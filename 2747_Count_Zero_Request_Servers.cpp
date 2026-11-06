//#2747 Count Zero Request Servers - https://leetcode.com/problems/count-zero-request-servers/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int> left, vector<int> right){
            return left[1] < right[1];
        });
        vector<int> idxs(queries.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](int left, int right){
            return queries[left] < queries[right];
        });
        vector<int> count(n + 1);
        int left = 0, right = 0, countActive = 0;
        vector<int> result(queries.size());
        for(auto &idx : idxs)
        {
            int query = queries[idx];
            while(right < (int)logs.size() && logs[right].back() <= query)
            {
                if(count[logs[right][0]]++ == 0)
                    countActive++;
                right++;
            }
            while(left < right && logs[left].back() + x < query)
            {
                if(--count[logs[left][0]] == 0)
                    countActive--;
                left++;
            }
            result[idx] = n - countActive;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenLogs = {{1, 3}, {2, 6}, {1, 5}};
    int givenX = 5;
    vector<int> givenQueries = {10, 11};
    vector<int> expectedAnswer = {1, 2};
    assert(solution.countServers(givenN, givenLogs, givenX, givenQueries) == expectedAnswer);

    givenN = 3;
    givenLogs = {{2, 4}, {2, 1}, {1, 2}, {3, 1}};
    givenX = 2;
    givenQueries = {3, 4};
    expectedAnswer = {0, 1};
    assert(solution.countServers(givenN, givenLogs, givenX, givenQueries) == expectedAnswer);

    return 0;
}
