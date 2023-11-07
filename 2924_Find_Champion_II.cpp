//#2924 Find Champion II - https://leetcode.com/problems/find-champion-ii/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> teams;
        for(int i = 0; i < n; i++)
            teams.insert(i);
        for(auto &edge : edges)
        {
            if(teams.count(edge[1]))
                teams.erase(edge[1]);
        }
        if(teams.size() == 1)
            return *(teams.begin());
        else
            return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_edges = {{0, 1}, {1, 2}};
    int given_n = 3;
    int expected_answer = 0;
    assert(solution.findChampion(given_n, given_edges) == expected_answer);

    given_edges = {{0, 2}, {1, 3}, {1, 2}};
    given_n = 4;
    expected_answer = -1;
    assert(solution.findChampion(given_n, given_edges) == expected_answer);

    return 0;
}
