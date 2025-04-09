//#779 K-th Symbol in Grammar - https://leetcode.com/problems/k-th-symbol-in-grammar/
#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>
using namespace std;

/*
class Solution{
private:
    int bst(int n, int k, int rootVal){
        if(n == 1)
            return rootVal;
        int totalNodes = pow(2, n - 1);
        if(k > totalNodes / 2)
        {
            int nextVal = rootVal == 1 ? 0 : 1;
            return bst(n - 1, k - (totalNodes / 2), nextVal);
        }
        int nextVal = rootVal == 1 ? 1 : 0;
        return bst(n - 1, k, nextVal);
    }
public:
    int kthGrammar(int n, int k){
       return bst(n, k, 0);
    }
};
*/

class Solution{
public:
    int kthGrammar(int n, int k){
       int flip = 0;
       while(n > 1)
       {
           int totalElem = pow(2, n - 1);
           if(k > totalElem / 2)
           {
               flip = !flip;
               k = k - (totalElem / 2);
           }
           n--;
       }
       return flip;
    }
};

int main()
{
    Solution solution;
    int given_n = 1;
    int given_k = 1;
    int expected_answer = 0;
    assert(solution.kthGrammar(given_n, given_k) == expected_answer);

    given_n = 3;
    given_k = 3;
    expected_answer = 1;
    assert(solution.kthGrammar(given_n, given_k) == expected_answer);

    return 0;
}
