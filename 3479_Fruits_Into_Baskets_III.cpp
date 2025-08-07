//#3479 Fruits Into Baskets III - https://leetcode.com/problems/fruits-into-baskets-iii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<int> segmentTree;
    vector<int> baskets;
    void build(int node, int left, int right)
    {
        if(left == right)
        {
            segmentTree[node] = baskets[left];
            return;
        }
        int mid = (left + right) >> 1;
        build(node << 1, left, mid);
        build(node << 1 | 1, mid + 1, right);
        segmentTree[node] = max(segmentTree[node << 1], segmentTree[node << 1 | 1]);
    }
    void update(int node, int left, int right, int idx){
        if(left == right)
        {
            segmentTree[node] = INT_MIN;
            return;
        }
        int mid = (left + right) >> 1;
        if(idx <= mid)
            update(node << 1, left, mid, idx);
        else
            update(node << 1 | 1, mid + 1, right, idx);
        segmentTree[node] = max(segmentTree[node << 1], segmentTree[node << 1 | 1]);
    }
    int query(int node, int left, int right, int &queryLeft, int &queryRight){
        if(left > queryRight || right < queryLeft)
            return INT_MIN;
        if(left >= queryLeft && right <= queryRight)
            return segmentTree[node];
        int mid = (left + right) >> 1;
        return max(query(node << 1, left, mid, queryLeft, queryRight), query(node << 1 | 1, mid + 1, right, queryLeft, queryRight));
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this->baskets = baskets;
        int n = fruits.size();
        segmentTree.resize(n * 4);
        int result = 0;
        build(1, 0, n - 1);
        for(int i = 0; i < n; i++)
        {
            int left = 0, right = n - 1, leftmostBasket = -1;
            while(left <= right)
            {
                int mid = (left + right) >> 1;
                if(query(1, 0, n - 1, left, mid) >= fruits[i])
                {
                    leftmostBasket = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            if(leftmostBasket != - 1)
                update(1, 0 , n - 1, leftmostBasket);
            else
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenFruits = {4, 2, 5};
    vector<int> givenBaskets = {3, 5, 4};
    int expectedAnswer = 1;
    assert(solution.numOfUnplacedFruits(givenFruits, givenBaskets) == expectedAnswer);

    givenFruits = {3, 6, 1};
    givenBaskets = {6, 4, 7};
    expectedAnswer = 0;
    assert(solution.numOfUnplacedFruits(givenFruits, givenBaskets) == expectedAnswer);

    return 0;
}
