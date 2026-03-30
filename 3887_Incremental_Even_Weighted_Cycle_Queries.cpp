//#3887 Incremental Even-Weighted Cycle Queries - https://leetcode.com/problems/incremental-even-weighted-cycle-queries/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    int findParent(int cur, vector<int> &parents, vector<int> &parity)
    {
        if(parents[cur] != cur)
        {
            int parent = findParent(parents[cur], parents, parity);
            parity[cur] ^= parity[parents[cur]];
            parents[cur] = parent;
        }
        return parents[cur];
    }
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parents(n);
        for(int i = 0; i < n; i++)
            parents[i] = i;
        vector<int> parity(n);
        int countEdges = 0;
        for(auto &edge : edges)
        {
            int parentLeft = findParent(edge[0], parents, parity);
            int parentRight = findParent(edge[1], parents, parity);
            if(parentLeft != parentRight)
            {
                parents[parentRight] = parentLeft;
                countEdges++;
                parity[parentRight] = parity[edge[0]] ^ parity[edge[1]] ^ edge[2];
            }
            else
            {
                if((parity[edge[0]] ^ parity[edge[1]] ^ edge[2]) == 0)
                    countEdges++;
            }
        }
        return countEdges;
    }
};



int main()
{
    Solution solution;
    int givenN = 3;
    vector<vector<int>> givenEdges = {{0, 1, 1}, {1, 2 ,1}, {0, 2, 0}};
    int expectedAnswer = 3;
    assert(solution.numberOfEdgesAdded(givenN, givenEdges) == expectedAnswer);

    givenN = 3;
    givenEdges = {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}};
    expectedAnswer = 2;
    assert(solution.numberOfEdgesAdded(givenN, givenEdges) == expectedAnswer);

    return 0;
}
