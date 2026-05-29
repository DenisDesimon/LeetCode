//#3093 Longest Common Suffix Queries - https://leetcode.com/problems/longest-common-suffix-queries/
#include <iostream>
#include <cassert>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class Trie{
private:
    static constexpr int n = 5e5 + 1, m = 26;
    int curNode;
    int trieNode[n][m];
    int shortestLength[n];
    int shortestIdx[n];
public:
    Trie(): curNode(0){
        for(int i = 0; i < n; i++)
        {
            memset(trieNode[i], 0, sizeof(trieNode[i]));
            shortestIdx[i] = -1;
            shortestLength[i] = INT_MAX;
        }
    }

    void clear(){
        for(int i = 0; i <= curNode; i++)
        {
            memset(trieNode[i], 0, sizeof(trieNode[i]));
            shortestIdx[i] = -1;
            shortestLength[i] = INT_MAX;
        }
        curNode = 0;
    }

    void insert(string &word, int idx){
        int cur = 0;
        if((int)word.size() < shortestLength[cur])
        {
            shortestLength[cur] = word.size();
            shortestIdx[cur] = idx;
        }
        for(auto &letter : word)
        {
            int let = letter - 'a';
            if(trieNode[cur][let] == 0)
                trieNode[cur][let] = ++curNode;
            cur = trieNode[cur][let];
            if(shortestLength[cur] > (int)word.size())
            {
                shortestLength[cur] = word.size();
                shortestIdx[cur] = idx;
            }
        }
    }

    int query(string &word){
        int cur = 0;
        for(auto &letter : word)
        {
            int let = letter - 'a';
            if(trieNode[cur][let] == 0)
                break;
            cur = trieNode[cur][let];
        }
        return shortestIdx[cur];
    }

};

Trie trie;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();
        vector<int> result;
        for(int i = 0; i < (int)wordsContainer.size(); i++)
        {
            string reversed = wordsContainer[i];
            reverse(reversed.begin(), reversed.end());
            trie.insert(reversed, i);
        }
        for(int i = 0; i < (int)wordsQuery.size(); i++)
        {
            string reversed = wordsQuery[i];
            reverse(reversed.begin(), reversed.end());
            result.push_back(trie.query(reversed));
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<string> givenWordsContainer = {"abcd", "bcd", "xbcd"};
    vector<string> givenWordsQuery = {"cd", "bcd", "xyz"};
    vector<int> expectedAnswer = {1, 1, 1};
    assert(solution.stringIndices(givenWordsContainer, givenWordsQuery) == expectedAnswer);

    givenWordsContainer = {"abcdefgh", "poiuygh", "ghghgh"};
    givenWordsQuery = {"gh", "acbfgh", "acbfegh"};
    expectedAnswer = {2, 0, 2};
    assert(solution.stringIndices(givenWordsContainer, givenWordsQuery) == expectedAnswer);

    return 0;
}
