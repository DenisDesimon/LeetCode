//#2976 Minimum Cost to Convert String I - https://leetcode.com/problems/minimum-cost-to-convert-string-i/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> letterCost(26, vector<long long>(26, LLONG_MAX));
        long long result = 0;
        for(int i = 0; i < (int)original.size(); i++)
        {
            letterCost[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i], letterCost[original[i] - 'a'][changed[i] - 'a']);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for(int i = 0; i < 26; i++)
        {
            pq.push({0, i});
            while(!pq.empty())
            {
                int curLetter = pq.top().second;
                long long curCost = pq.top().first;
                pq.pop();
                if(curCost > letterCost[i][curLetter])
                    continue;
                for(int j = 0; j < 26; j++)
                {
                    if(letterCost[curLetter][j] != LLONG_MAX && (curCost + letterCost[curLetter][j] <= letterCost[i][j]))
                    {
                        letterCost[i][j] = curCost + letterCost[curLetter][j];
                        pq.push({letterCost[i][j], j});
                    }
                }
            }
        }
        for(int i = 0; i < (int)source.size(); i++)
        {
            if(source[i] != target[i])
            {
                if(letterCost[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX)
                    return -1;
                result += letterCost[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_source = "aaadbdcdac";
    string given_target = "cdbabaddba";
    vector<char> given_original  = {'a','c','b','d','b','a','c'};
    vector<char> given_changed  = {'c','a','d','b','c','b','d'};
    vector<int> given_cost = {7, 2, 1, 3, 6, 1, 7};
    long long expected_answer = 39;
    assert(solution.minimumCost(given_source, given_target, given_original, given_changed, given_cost) == expected_answer);

    given_source = "abcd";
    given_target = "acbe";
    given_original  = {'a', 'b', 'c', 'c', 'e', 'd'};
    given_changed  = {'b', 'c', 'b', 'e', 'b', 'e'};
    given_cost = {2, 5, 5, 1, 2, 20};
    expected_answer = 28;
    assert(solution.minimumCost(given_source, given_target, given_original, given_changed, given_cost) == expected_answer);

    return 0;
}
