//#386 Lexicographical Numbers - https://leetcode.com/problems/lexicographical-numbers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void build(int start, int& n, vector<int>& result){
        if(start > n)
            return;
        result.push_back(start);
        for(int digit = 0; digit <= 9; digit++)
            build(start * 10 + digit, n, result);

    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int start = 1; start <= min(n, 9); start++)
            build(start, n, result);
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 13;
    vector<int> expected_answer = {1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(solution.lexicalOrder(given_n) == expected_answer);

    given_n = 5;
    expected_answer = {1, 2, 3, 4, 5};
    assert(solution.lexicalOrder(given_n) == expected_answer);

    return 0;
}
