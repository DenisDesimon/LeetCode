//#2977 Minimum Cost to Convert String II - https://leetcode.com/problems/minimum-cost-to-convert-string-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Trie{
    Trie *child[26] = {nullptr};
    int id = -1;
};

int add(Trie *node, string &word, int &index)
{
    for(auto &letter : word)
    {
        int encoded = letter - 'a';
        if(!node->child[encoded])
            node->child[encoded] = new Trie();
        node = node->child[encoded];
    }
    if(node->id == -1)
        node->id = ++index;
    return node->id;
}

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int inf = INT_MAX / 2;
        int n = source.size();
        int m = original.size();
        Trie *root = new Trie();
        int index = -1;
        vector<vector<int>> replaceCost(2 * m, vector<int>(2 * m, inf));
        for(int i = 0; i < 2 * m; i++)
            replaceCost[i][i] = 0;
        for(int i = 0; i < m; i++)
        {
            int x = add(root, original[i], index);
            int y = add(root, changed[i], index);
            replaceCost[x][y] = min(replaceCost[x][y], cost[i]);
        }
        for(int k = 0; k <= index; k++)
        {
            for(int i = 0; i <= index; i++)
            {
                for(int j = 0; j <= index; j++)
                {
                    replaceCost[i][j] = min(replaceCost[i][j], replaceCost[i][k] + replaceCost[k][j]);
                }
            }
        }
        vector<long long> dp(n, LLONG_MAX);
        for(int i = 0; i < n; i++)
        {
            if(i != 0 && dp[i - 1] == LLONG_MAX)
                continue;
            long long prev = i == 0 ? 0 : dp[i - 1];
            if(source[i] == target[i])
                dp[i] = min(dp[i], prev);
            Trie *x = root;
            Trie *y = root;
            for(int j = i; j < n; j++)
            {
                x = x->child[source[j] - 'a'];
                y = y->child[target[j] - 'a'];
                if(!x || !y)
                    break;
                if(x->id != -1 && y->id != -1 && replaceCost[x->id][y->id] != inf)
                    dp[j] = min(dp[j], prev + replaceCost[x->id][y->id]);
            }
        }
        return dp.back() == LLONG_MAX ? - 1 : dp.back();
    }
};

int main()
{
    Solution solution;
    string givenSource = "abcd";
    string givenTarget = "acbe";
    vector<string> givenOriginal  = {"a", "b", "c", "c", "e", "d"};
    vector<string> givenChanged  = {"b", "c", "b", "e", "b", "e"};
    vector<int> givenCost = {2, 5, 5, 1, 2, 20};
    long long expected_answer = 28;
    assert(solution.minimumCost(givenSource, givenTarget, givenOriginal, givenChanged, givenCost) == expected_answer);

    givenSource = "abcdefgh";
    givenTarget = "acdeeghh";
    givenOriginal  = {"bcd", "fgh", "thh"};
    givenChanged  = {"cde", "thh", "ghh"};
    givenCost = {1, 3, 5};
    expected_answer = 9;
    assert(solution.minimumCost(givenSource, givenTarget, givenOriginal, givenChanged, givenCost) == expected_answer);

    return 0;
}
