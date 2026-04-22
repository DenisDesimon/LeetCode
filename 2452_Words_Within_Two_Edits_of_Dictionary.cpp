//#2452 Words Within Two Edits of Dictionary - https://leetcode.com/problems/words-within-two-edits-of-dictionary/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

struct Trie{
    Trie* child[26];
    bool isEnd;
    Trie(){
        fill(child, child + 26, nullptr);
        isEnd = false;
    }
};

class Solution {
private:
    Trie* root;
    void insert(string &word)
    {
        Trie* cur = root;
        for(auto &letter : word)
        {
            if(!cur->child[letter - 'a'])
                cur->child[letter - 'a'] = new Trie();
            cur = cur->child[letter - 'a'];
        }
        cur->isEnd = true;
    }
    bool dfs(string &word, int cur, Trie* node, int swaps)
    {
        if(cur == (int)word.size())
            return node->isEnd;
        if(node->child[word[cur] - 'a'])
        {
            if(dfs(word, cur + 1, node->child[word[cur] - 'a'], swaps))
                return true;
        }
        if(swaps < 2)
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->child[i])
                {
                    if(dfs(word, cur + 1, node->child[i], swaps + 1))
                        return true;
                }
            }
        }
        return false;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        root = new Trie();
        vector<string> result;
        for(auto &dict : dictionary)
            insert(dict);
        for(auto &query : queries)
        {
            if(dfs(query, 0, root, 0))
                result.push_back(query);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenQueries = {"word", "note", "ants", "wood"};
    vector<string> givenDictionary = {"wood", "joke", "moat"};
    vector<string> expectedAnswer = {"word", "note", "wood"};
    assert(solution.twoEditWords(givenQueries, givenDictionary) == expectedAnswer);

    givenQueries = {"yes"};
    givenDictionary = {"not"};
    expectedAnswer = {};
    assert(solution.twoEditWords(givenQueries, givenDictionary) == expectedAnswer);

    return 0;
}
