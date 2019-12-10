//#519 Random Flip Matrix - https://leetcode.com/problems/random-flip-matrix/
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int n, m;
    unordered_set<int> used;
public:
    Solution(int n_rows, int n_cols) {
        n = n_rows, m = n_cols;
    }

    vector<int> flip() {
        if((int)used.size() == n * m)
            return {};
        int rand_num = rand() % (n * m);
        while(used.count(rand_num))
            rand_num = (rand_num + 1) % (n * m);
        used.insert(rand_num);
        return {rand_num % n, rand_num / n};
    }

    void reset() {
       used.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main()
{
    int given_rows = 10, given_cols = 2;
    Solution solution(given_rows, given_cols);
    assert(solution.flip() != solution.flip());

    return 0;
}
