//#208 Implement Trie (Prefix Tree) - https://leetcode.com/problems/implement-trie-prefix-tree/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> next;
    bool is_end = false;
};

class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        for(char &ch : word)
        {
            if(!cur->next.count(ch))
                cur->next[ch] = new TrieNode;
            cur = cur->next[ch];
        }
        cur->is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = root;
        for(auto &ch : word)
        {
            if(!cur->next.count(ch))
                return false;
            cur = cur->next[ch];
        }
        return cur->is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = root;
        for(auto &ch : prefix)
        {
            if(!cur->next.count(ch))
                return false;
            cur = cur->next[ch];
        }
        return true;
    }
};

int main()
{
    Trie solution;
    solution.insert("apple");
    bool expected_answer = true;
    assert(solution.search("apple") == expected_answer);

    expected_answer = false;
    assert(solution.search("app") == expected_answer);

    expected_answer = true;
    assert(solution.startsWith("app") == expected_answer);

    solution.insert("app");
    assert(solution.search("app") == expected_answer);

    return 0;
}
