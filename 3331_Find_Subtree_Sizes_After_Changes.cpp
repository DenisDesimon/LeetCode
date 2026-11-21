//#3331 Find Subtree Sizes After Changes - https://leetcode.com/problems/find-subtree-sizes-after-changes/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void dfs(int cur, int parent, int closestNode[], vector<vector<int>> &connections, vector<int> &result, string &s){
        int letter = s[cur] - 'a';
        int prev = closestNode[letter];
        int nextParent = (prev != -1) ? prev : parent;
        closestNode[letter] = cur;
        for(auto &next : connections[cur])
            dfs(next, cur, closestNode, connections, result, s);
        closestNode[letter] = prev;
        if(nextParent != -1)
            result[nextParent] += result[cur];
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> result(n, 1);
        int closestNode[26];
        for(int i = 0; i < 26; i++)
            closestNode[i] = -1;
        vector<vector<int>> connections(n);
        for(int i = 0; i < n; i++)
        {
            if(parent[i] != -1)
                connections[parent[i]].push_back(i);
        }
        dfs(0, -1, closestNode, connections, result, s);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenParent = {-1, 0, 4, 0, 1};
    string givenS = "abbba";
    vector<int> expectedAnswer = {5, 2, 1, 1, 1};
    assert(solution.findSubtreeSizes(givenParent, givenS) == expectedAnswer);

    givenParent = {-1, 0, 0, 1, 1, 1};
    givenS = "abaabc";
    expectedAnswer = {6, 3, 1, 1, 1, 1};
    assert(solution.findSubtreeSizes(givenParent, givenS) == expectedAnswer);

    return 0;
}
