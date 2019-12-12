//#526 Beautiful Arrangement - https://leetcode.com/problems/beautiful-arrangement/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
    void backtrack(int cur_pos, int& N, bool visited[], int& result){
        if(cur_pos == N + 1)
        {
            result++;
            return;
        }
        for(int i = 1; i <= N; i++)
        {
            if(visited[i] || (i % cur_pos && cur_pos % i))
                continue;
            visited[i] = true;
            backtrack(cur_pos + 1, N, visited, result);
            visited[i] = false;
        }
    }
 public:
     int countArrangement(int N) {
         int result = 0;
         bool visited[N + 1] = {0};
         backtrack(1, N, visited, result);
         return result;
     }
 };

int main()
{
    Solution solution;
    int given_N = 2;
    int expected_answer = 2;
    assert(solution.countArrangement(given_N) == expected_answer);

    given_N = 7;
    expected_answer = 41;
    assert(solution.countArrangement(given_N) == expected_answer);

    return 0;
}
