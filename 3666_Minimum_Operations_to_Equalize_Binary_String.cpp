//#3666 Minimum Operations to Equalize Binary String - https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution{
public:
    int minOperations(string s, int k){
        int n = s.size(), countZeroes = 0;
        for(auto &bit : s)
        {
            if(bit == '0')
                countZeroes++;
        }
        set<int> nodes[2];
        vector<int> dist(n + 1, INT_MAX);
        queue<int> q;
        q.push(countZeroes);
        dist[countZeroes] = 0;
        for(int i = 0; i <= n; i++)
        {
            nodes[i % 2].insert(i);
        }
        nodes[countZeroes % 2].erase(countZeroes);
        while(!q.empty())
        {
            int curZeroes = q.front();
            q.pop();
            int maxZeroes = min(k, curZeroes);
            int minZeroes = max(0, k - n + curZeroes);
            int leftBorder = curZeroes + k - 2 * maxZeroes;
            int rightBorder = curZeroes + k - 2 * minZeroes;
            auto &curNode = nodes[leftBorder % 2];
            for(auto iter = curNode.lower_bound(leftBorder); iter != curNode.end() && *iter <= rightBorder; )
            {
                dist[*iter] = dist[curZeroes] + 1;
                q.push(*iter);
                iter = curNode.erase(iter);
            }

        }
        return dist[0] == INT_MAX ? -1 : dist[0];
    }
};

int main()
{
    Solution solution;
    string givenS = "101";
    int givenK = 2;
    int expectedAnswer = -1;
    assert(solution.minOperations(givenS, givenK) == expectedAnswer);

    givenS = "110";
    givenK = 1;
    expectedAnswer = 1;
    assert(solution.minOperations(givenS, givenK) == expectedAnswer);

    return 0;
}
