//1970 Last Day Where You Can Still Cross - https://leetcode.com/problems/last-day-where-you-can-still-cross/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class DSU{
    vector<int> root, size;
public:
    DSU(int n): root(n), size(n, 1)
    {
        for(int i = 0; i < n; i++)
            root[i] = i;
    }
    int find(int x){
        if(root[x] != x)
            root[x] = find(root[x]);
        return root[x];
    }
    void unite(int x, int y){
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY)
            return;
        if(size[rootX] > size[rootY])
            swap(rootX, rootY);
        root[rootX] = rootY;
        size[rootY] += size[rootX];
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DSU dsu(row * col + 2);
        vector<vector<bool>> map(row, vector<bool>(col));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = cells.size() - 1; i >= 0; i--)
        {
            int curRow = cells[i][0] - 1, curCol = cells[i][1] - 1;
            map[curRow][curCol] = true;
            int id1 = curRow * col + curCol + 1;
            for(auto &direction : directions)
            {
                int newRow = curRow + direction[0], newCol = curCol + direction[1];
                if(newRow >= 0 && newRow < row && newCol >=0 && newCol < col && map[newRow][newCol])
                {
                    int id2 = newRow * col + newCol + 1;
                    dsu.unite(id1, id2);
                }
            }

            if(curRow == 0)
                dsu.unite(0, id1);
            else if(curRow == row - 1)
                dsu.unite(row * col + 1, id1);

            if(dsu.find(0) == dsu.find(row * col + 1))
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int givenRow = 2;
    int givenCol = 2;
    vector<vector<int>> givenCells = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    int expectedAnswer = 1;
    assert(solution.latestDayToCross(givenRow, givenCol, givenCells) == expectedAnswer);

    givenRow = 3;
    givenCol = 3;
    givenCells = {{1,2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}, {1, 3}, {2, 3}, {3, 2}, {3, 1}};
    expectedAnswer = 3;
    assert(solution.latestDayToCross(givenRow, givenCol, givenCells) == expectedAnswer);

    return 0;
}
