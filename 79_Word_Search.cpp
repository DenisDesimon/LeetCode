//#79 Word Search - https://leetcode.com/problems/word-search/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool exist(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int cur_x, int cur_y, int cur_pos){
        if(visited[cur_x][cur_y])
            return false;
        if(cur_pos + 1 == (int)word.size())
            return true;
        bool result = false;
        visited[cur_x][cur_y] = true;
        if(cur_x > 0 && board[cur_x - 1][cur_y] == word[cur_pos + 1])
            result = result || exist(board, word, visited, cur_x - 1, cur_y, cur_pos + 1);
        if(cur_x + 1 < (int)board.size() && board[cur_x + 1][cur_y] == word[cur_pos + 1])
            result = result || exist(board, word, visited, cur_x + 1, cur_y, cur_pos + 1);
        if(cur_y > 0 && board[cur_x][cur_y - 1] == word[cur_pos + 1])
            result = result || exist(board, word, visited, cur_x, cur_y - 1, cur_pos + 1);
        if(cur_y + 1 < (int)board[0].size() && board[cur_x][cur_y + 1] == word[cur_pos + 1])
            result = result || exist(board, word, visited, cur_x, cur_y + 1, cur_pos + 1);
        visited[cur_x][cur_y] = false;
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool result = false;
        for(int i = 0; i < (int)board.size(); i++)
        {
            for(int j = 0; j < (int)board[0].size(); j++)
            {
                if(board[i][j] == word[0])
                    result = result || exist(board, word, visited, i, j, 0);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_board = {{'a'}, {'a'}};
    string given_word = "aaa";
    bool expected_answer = false;
    assert(solution.exist(given_board, given_word) == expected_answer);

    given_board = {{'A', 'B', 'C', 'E'},
                   {'S', 'F', 'C', 'S'},
                   {'A', 'D', 'E', 'E'}};
    given_word = "ABCCED";
    expected_answer = true;
    assert(solution.exist(given_board, given_word) == expected_answer);

    return 0;
}
