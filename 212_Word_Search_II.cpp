//#212 Word Search II - https://leetcode.com/problems/word-search-ii/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

struct TrieNode{
    unordered_map<char, TrieNode*> next;
    bool is_end = false;
};

class Trie{
    TrieNode* root;
public:
    Trie() : root(new TrieNode()){}
     void insert(string word) {
         auto cur = root;
         for(auto &ch : word)
         {
             if(!cur->next.count(ch))
                 cur->next[ch] = new TrieNode;
             cur = cur->next[ch];
         }
         cur->is_end = true;
     }
     TrieNode* get_root(){
         return root;
     }

};

class Solution {
    void dfs(vector<vector<char>>& board, Trie& dictionary, vector<string>& result, string& word, int row, int col, TrieNode* cur_node){
        word.push_back(board[row][col]);
        cur_node = cur_node->next[board[row][col]];
        if(cur_node->is_end)
        {
            result.push_back(word);
            cur_node->is_end = false;
            if(cur_node->next.empty())
            {
                word.pop_back();
                return;
            }
        }
        char ch = board[row][col];
        board[row][col] = '#';
        if(row + 1 < (int)board.size() && cur_node->next.count(board[row + 1][col]))
            dfs(board, dictionary, result, word, row + 1, col, cur_node);
        if(row > 0 && cur_node->next.count(board[row - 1][col]))
            dfs(board, dictionary, result, word, row - 1, col, cur_node);
        if(col + 1 < (int)board[0].size() && cur_node->next.count(board[row][col + 1]))
            dfs(board, dictionary, result, word, row, col + 1, cur_node);
        if(col > 0 && cur_node->next.count(board[row][col - 1]))
            dfs(board, dictionary, result, word, row, col - 1, cur_node);
        board[row][col] = ch;
        word.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie dictionary;
        vector<string> result;
        string word;
        for(auto &word : words)
            dictionary.insert(word);
        for(int i = 0; i < (int)board.size(); i++)
        {
            for(int j = 0; j < (int)board[0].size(); j++)
            {
                if(dictionary.get_root()->next.count(board[i][j]))
                    dfs(board, dictionary, result, word, i, j, dictionary.get_root());
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> given_words = {"oath", "pea", "eat", "rain"};
    vector<string> expected_answer = {"oath", "eat"};
    assert(solution.findWords(given_board, given_words) == expected_answer);

    given_board = {{'a', 'b'}, {'c', 'd'}};
    given_words = {"ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb"};
    expected_answer = {"ac", "ab", "bd", "ca", "db"};
    assert(solution.findWords(given_board, given_words) == expected_answer);

    return 0;
}
