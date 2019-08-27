//#211 Add and Search Word - Data structure design - https://leetcode.com/problems/add-and-search-word-data-structure-design/
#include <iostream>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> next;
    bool is_end = false;
};

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode) {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur = root;
        for(char &ch : word)
        {
            if(!cur->next.count(ch))
                cur->next[ch] = new TrieNode;
            cur = cur->next[ch];
        }
        cur->is_end = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<TrieNode*> nodes;
        nodes.push(root);
        for(int i = 0; i < (int)word.size(); i++)
        {
            if(nodes.empty())
                return false;
            int size_nodes = nodes.size();
            if(word[i] == '.')
            {
                while(size_nodes--)
                {
                    auto cur_node = nodes.front();
                    nodes.pop();
                    for(auto iter = cur_node->next.begin(); iter != cur_node->next.end(); iter++)
                        nodes.push(iter->second);
                }
            }
            else
            {
                while(size_nodes--)
                {
                    auto cur_node = nodes.front();
                    nodes.pop();
                    if(cur_node->next.count(word[i]))
                        nodes.push(cur_node->next[word[i]]);
                }
            }
        }
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            if(cur_node->is_end)
                return true;
        }
        return false;
    }
};

int main()
{
    WordDictionary solution;
    solution.addWord("bad");
    solution.addWord("mab");
    bool expected_answer = true;
    assert(solution.search(".ad") == expected_answer);

    expected_answer = false;
    assert(solution.search("pad") == expected_answer);

    expected_answer = true;
    assert(solution.search("b..") == expected_answer);

    return 0;
}
