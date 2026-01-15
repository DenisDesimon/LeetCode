//#3454 Separate Squares II - https://leetcode.com/problems/separate-squares-ii/
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

class SegmentTree{
private:
    vector<int> xs;
    vector<int> countCover;
    vector<int> coverLength;
    int n;
    void modify(int xPointLeft, int xPointRight, int val, int treeLeft, int treeRight, int curPos)
    {
        if(xPointLeft >= xs[treeRight + 1] || xPointRight <= xs[treeLeft])
            return;
        if(xPointLeft <= xs[treeLeft] && xPointRight >= xs[treeRight + 1])
            countCover[curPos] += val;
        else
        {
            int mid = (treeLeft + treeRight) / 2;
            modify(xPointLeft, xPointRight, val, treeLeft, mid, curPos * 2 + 1);
            modify(xPointLeft, xPointRight, val, mid + 1, treeRight, curPos * 2 + 2);
        }
        if(countCover[curPos])
            coverLength[curPos] = xs[treeRight + 1] - xs[treeLeft];
        else
        {
            if(treeLeft == treeRight)
                coverLength[curPos] = 0;
            else
                coverLength[curPos] = coverLength[curPos * 2 + 1] + coverLength[curPos * 2 + 2];
        }
    }
public:
    SegmentTree(vector<int> &xCoord) : xs(xCoord)
    {
        n = xCoord.size() - 1;
        countCover.resize(n * 4);
        coverLength.resize(n * 4);
    }
    void update(int xPointLeft, int xPointRight, int val)
    {
        modify(xPointLeft, xPointRight, val, 0, n - 1, 0);
    }
    int getCoverLength()
    {
        return coverLength[0];
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;
        for(auto &square : squares)
        {
            events.push_back({square[1], 1, square[0], square[0] + square[2]});
            events.push_back({square[1] + square[2], -1, square[0], square[0] + square[2]});
            xsSet.insert(square[0]);
            xsSet.insert(square[0] + square[2]);
        }
        sort(events.begin(), events.end());
        vector<int> xs(xsSet.begin(), xsSet.end());
        SegmentTree tree(xs);
        double totalArea = 0;
        vector<double> prevAreas;
        vector<int> widths;
        int prev = get<0>(events.front());
        for(auto &[y, val, xLeft, xRight] : events)
        {
            long long len = tree.getCoverLength();
            totalArea += len * (y - prev);
            tree.update(xLeft, xRight, val);
            prevAreas.push_back(totalArea);
            widths.push_back(tree.getCoverLength());
            prev = y;
        }
        long long target = (totalArea + 1) / 2;
        int idx = lower_bound(prevAreas.begin(), prevAreas.end(), target) - prevAreas.begin() - 1;
        double prevArea = prevAreas[idx];
        int curWidth = widths[idx];
        int curY = get<0>(events[idx]);
        return (totalArea / 2 - prevArea) / curWidth + curY;
    }
};

int main()
{
    Solution solution;
    double precise = 1e-5;
    vector<vector<int>> givenSquares = {{0, 0, 2}, {1, 1, 1}};
    double expectedAnswer = 1.0;
    assert(abs(solution.separateSquares(givenSquares) - expectedAnswer) < precise);

    givenSquares = {{15, 21, 2}, {19, 21, 3}};
    expectedAnswer = 22.30;
    assert(abs(solution.separateSquares(givenSquares) - expectedAnswer) < precise);

    return 0;
}
