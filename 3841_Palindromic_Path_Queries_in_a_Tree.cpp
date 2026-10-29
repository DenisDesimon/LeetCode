//#3841 Palindromic Path Queries in a Tree - https://leetcode.com/problems/palindromic-path-queries-in-a-tree/
#include <iostream>
#include <cassert>
#include <vector>
#include <sstream>
using namespace std;


class BIT{
    int n;
    vector<int> tree;
public:
    BIT(int size) : n(size), tree(size + 1){}
    void update(int idx, int delta){
        while(idx <= n){
            tree[idx] ^= delta;
            idx += idx & (-idx);
        }
    }
    int query(int idx){
        int result = 0;
        while(idx)
        {
            result ^= tree[idx];
            idx -= idx & (-idx);
        }
        return result;
    }
};

class Solution {

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> connections(n);
        for(auto &edge : edges)
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        int ancestorLevels = 32 - __builtin_clz(n);
        vector<vector<int>> ancestors(n, vector<int>(ancestorLevels));
        vector<int> depth(n), positions(n), subTreeEndPos(n);
        int pos = 0;
        auto dfs = [&](auto &&dfs, int cur, int prev) -> void{
            positions[cur] = ++pos;
            ancestors[cur][0] = prev;
            for(int next : connections[cur])
            {
                if(next == prev)
                    continue;
                depth[next] = depth[cur] + 1;
                dfs(dfs, next, cur);
            }
            subTreeEndPos[cur] = pos;
        };
        dfs(dfs, 0, 0);
        for(int j = 1; j < ancestorLevels; j++)
        {
            for(int i = 0; i < n; i++)
            {
                ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
            }
        }
        auto lowCommAncestor = [&](int left, int right){
            if(depth[left] < depth[right])
                swap(left, right);
            int diff = depth[left] - depth[right];
            for(int i = 0; i < ancestorLevels; i++)
            {
                if((1 << i) & diff)
                    left = ancestors[left][i];
            }
            if(left == right)
                return left;
            for(int i = ancestorLevels - 1; i >= 0; --i)
            {
                if(ancestors[right][i] != ancestors[left][i])
                {
                    left = ancestors[left][i];
                    right = ancestors[right][i];
                }
            }
            return ancestors[left][0];
        };
        BIT bit(n + 1);
        for(int i = 0; i < n; i++)
        {
            bit.update(positions[i], 1 << (s[i] - 'a'));
            bit.update(subTreeEndPos[i] + 1, 1 << (s[i] - 'a'));
        }

        vector<bool> result;
        for(auto &query : queries)
        {
            stringstream ss(query);
            string operation;
            ss >> operation;
            if(operation == "update")
            {
                int idx;
                char letter;
                ss >> idx >> letter;
                bit.update(positions[idx],  (1 << (s[idx] - 'a')) ^ (1 << (letter - 'a')));
                bit.update(subTreeEndPos[idx] + 1, (1 << (s[idx] - 'a')) ^ (1 << (letter - 'a')));
                s[idx] = letter;
            }
            else
            {
                int left, right;
                ss >> left >> right;
                int commonAncestor = lowCommAncestor(left, right);
                int mask = bit.query(positions[left]) ^ bit.query(positions[right]) ^ (1 << (s[commonAncestor] - 'a'));
                result.push_back(__builtin_popcount(mask) <= 1);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenEdges = {{0, 1}, {1, 2}};
    string givenS = "aac";
    vector<string> givenQueries = {"query 0 2", "update 1 b", "query 0 2"};
    vector<bool> expectedAnswer = {true, false};
    assert(solution.palindromePath(givenN, givenEdges, givenS, givenQueries) == expectedAnswer);

    givenN = 4;
    givenEdges = {{0, 1}, {0, 2}, {0, 3}};
    givenS = "abca";
    givenQueries = {"query 1 2", "update 0 b", "query 2 3", "update 3 a", "query 1 3"};
    expectedAnswer = {false, false, true};
    assert(solution.palindromePath(givenN, givenEdges, givenS, givenQueries) == expectedAnswer);


    return 0;
}
