//#2438 Range Product Queries of Powers - https://leetcode.com/problems/range-product-queries-of-powers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> binaryRepresent;
        vector<int> result;
        int i = 0;
        while(n)
        {
            if(n & 1)
                binaryRepresent.push_back(1 << i);
            i++;
            n >>= 1;
        }
        vector<vector<int>> prefix(binaryRepresent.size(), vector<int>(binaryRepresent.size()));
        for(int i = 0; i < (int)prefix.size(); i++)
        {
            long long product = 1;
            for(int j = i; j < (int)prefix.size(); j++)
            {
                product = product * binaryRepresent[j] % mod;
                prefix[i][j] = product;
            }
        }
        for(auto &query : queries)
            result.push_back(prefix[query[0]][query[1]]);
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 15;
    vector<vector<int>> givenQueries = {{0, 1}, {2, 2}, {0, 3}};
    vector<int> expectedAnswer = {2, 4, 64};
    assert(solution.productQueries(givenN, givenQueries) == expectedAnswer);

    givenN = 2;
    givenQueries = {{0, 0}};
    expectedAnswer = {2};
    assert(solution.productQueries(givenN, givenQueries) == expectedAnswer);

    return 0;
}
