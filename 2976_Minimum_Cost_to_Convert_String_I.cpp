#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
       vector<vector<long long>> prices(26, vector<long long>(26, INT_MAX));
       long long result = 0;
       for(int i = 0; i < (int)original.size(); i++)
           prices[original[i] - 'a'][changed[i] - 'a'] = min(prices[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
       for(int k = 0; k < 26; k++)
           for(int i = 0; i < 26; i++)
               for(int j = 0; j < 26; j++)
                   prices[i][j] = min(prices[i][j], prices[i][k] + prices[k][j]);
       for(int i = 0; i < (int)source.size(); i++)
       {
           if(source[i] == target[i])
               continue;
           if(prices[source[i] - 'a'][target[i] - 'a'] >= INT_MAX)
               return -1;
           result += prices[source[i] - 'a'][target[i] - 'a'];
       }
       return result;

    }
};

int main()
{
    Solution solution;
    string given_source = "aaadbdcdac";
    string given_target = "cdbabaddba";
    vector<char> given_original  = {'a','c','b','d','b','a','c'};
    vector<char> given_changed  = {'c','a','d','b','c','b','d'};
    vector<int> given_cost = {7, 2, 1, 3, 6, 1, 7};
    long long expected_answer = 39;
    assert(solution.minimumCost(given_source, given_target, given_original, given_changed, given_cost) == expected_answer);

    given_source = "abcd";
    given_target = "acbe";
    given_original  = {'a', 'b', 'c', 'c', 'e', 'd'};
    given_changed  = {'b', 'c', 'b', 'e', 'b', 'e'};
    given_cost = {2, 5, 5, 1, 2, 20};
    expected_answer = 28;
    assert(solution.minimumCost(given_source, given_target, given_original, given_changed, given_cost) == expected_answer);

    return 0;
}
