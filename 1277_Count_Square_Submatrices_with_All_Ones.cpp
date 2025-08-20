#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> vert(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        vector<vector<int>> hor = vert;
        int result = 0;
        for(int i = 0; i < (int)matrix.size(); i++)
        {
            for(int j = 0; j < (int)matrix[0].size(); j++)
            {
                if(matrix[i][j])
                {
                    vert[i + 1][j + 1] = vert[i][j +  1] + 1;
                    hor[i + 1][j + 1] = hor[i + 1][j] + 1;
                }
            }
        }
        for(int i = 0; i < (int)matrix.size(); i++)
        {
            for(int j = 0; j < (int)matrix[0].size(); j++)
            {
                int size = min(hor[i + 1][j + 1], vert[i + 1][j + 1]);
                while(size)
                {
                    int len = 1;
                    for(; len < size; len++)
                    {
                        if(vert[i + 1][j + 1 - len] < size || hor[i + 1 - len][j + 1] < size)
                        {
                            break;
                        }
                    }
                    if(len == size)
                    {
                        result += size;
                        break;
                    }
                    size--;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{0,1,1,1}, {1,1,1,1}, {0,1,1, 1}};
    solution.countSquares(given_matrix);
    return 0;
}
