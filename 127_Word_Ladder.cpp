//#127 Word Ladder - https://leetcode.com/problems/word-ladder/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
    bool has_edge(string& left, string& right){
        bool has_differ = false;
        for(int i = 0; i < (int)left.size(); i++)
        {
            if(left[i] == right[i])
                continue;
            else if(!has_differ)
                has_differ = true;
            else
                return false;
        }
        return has_differ;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int index_end = 0;
        for(;index_end < (int)wordList.size(); index_end++)
        {
            if(wordList[index_end] == endWord)
                break;
        }
        if(index_end == (int)wordList.size())
            return 0;
        int result = 1;
        queue<int> nodes;
        wordList.push_back(beginWord);
        nodes.push(wordList.size() - 1);
        vector<vector<int>> graph(wordList.size());
        vector<bool> visited(wordList.size(), false);
        for(int i = 0; i < (int)wordList.size(); i++)
        {
            for(int j = i + 1; j < (int)wordList.size(); j++)
            {
                if(has_edge(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        if(graph[index_end].empty() || graph[wordList.size() - 1].empty())
            return 0;
        while(!nodes.empty())
        {
            int size_nodes = nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(visited[cur_node])
                    continue;
                if(cur_node == index_end)
                    return result;
                visited[cur_node] = true;
                for(auto node : graph[cur_node])
                    nodes.push(node);
            }
            result++;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    string given_begin = "hit";
    string given_end = "cog";
    vector<string> given_word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    int expected_answer = 5;
    assert(solution.ladderLength(given_begin, given_end, given_word_list) == expected_answer);

    given_begin = "hit";
    given_end = "cog";
    given_word_list = {"hot", "dot", "dog", "lot", "log"};
    expected_answer = 0;
    assert(solution.ladderLength(given_begin, given_end, given_word_list) == expected_answer);

    return 0;
}
