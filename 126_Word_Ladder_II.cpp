//#126 Word Ladder II - https://leetcode.com/problems/word-ladder-ii/
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
            if(!has_differ)
                has_differ = true;
            else
                return false;
        }
        return has_differ;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int index_end = 0;
        for(; index_end < (int)wordList.size(); index_end++)
        {
            if(wordList[index_end] == endWord)
                break;
        }
        if(index_end == (int)wordList.size())
            return {};
        vector<vector<string>> result;
        wordList.push_back(beginWord);
        vector<vector<int>> graph(wordList.size());
        queue<pair<int, vector<int>>> nodes;
        vector<bool> visited(wordList.size());
        nodes.push({(int)wordList.size() - 1, {(int)wordList.size() - 1}});
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
            return result;
        bool has_found = false;
        while(!nodes.empty())
        {
            int size_nodes = nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                visited[cur_node.first] = true;
                for(auto &node : graph[cur_node.first])
                {
                    if(node == index_end)
                    {
                        result.push_back({});
                        for(auto &idx : cur_node.second)
                            result.back().push_back(wordList[idx]);
                        result.back().push_back(wordList[node]);
                        has_found = true;
                    }
                    if(visited[node])
                        continue;
                    cur_node.second.push_back(node);
                    nodes.push({node, cur_node.second});
                    cur_node.second.pop_back();
                }
            }
            if(has_found)
                return result;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_begin = "red";
    string given_end = "tax";
    vector<string> given_word_list = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};

    vector<vector<string>> expected_answer = {{"red", "ted", "tex", "tax"}, {"red", "ted", "tad", "tax"},
                                              {"red", "rex", "tex", "tax"}};
    assert(solution.findLadders(given_begin, given_end, given_word_list) == expected_answer);

    given_begin = "hit";
    given_end = "cog";
    given_word_list = {"hot", "dot", "dog", "lot", "log", "cog"};

    expected_answer = {{"hit", "hot", "dot", "dog", "cog"},
                                             {"hit", "hot", "lot", "log", "cog"}};
    assert(solution.findLadders(given_begin, given_end, given_word_list) == expected_answer);

    return 0;
}
