//#Leftmost Column with at Least a One - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3306/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
 * (This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in
non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it.
If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions
that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples.
You will not have access the binary matrix directly.
*/

  // This is the BinaryMatrix's API interface.
  // You should not implement it, or speculate about its implementation
  class BinaryMatrix {
      vector<vector<int>> matrix;
    public:
      BinaryMatrix(vector<vector<int>> given_matrix){
          matrix = given_matrix;
      }
      int get(int x, int y){
          return matrix[x][y];
      }
      vector<int> dimensions(){
          return {(int)matrix.size(), (int)matrix[0].size()};
      }
  };


  class Solution {
  public:
      int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
          vector<int> dim = binaryMatrix.dimensions();
          int result = -1;
          int i = 0, j = dim[1] - 1;
          while(i < dim[0] && j >= 0)
          {
              if(binaryMatrix.get(i, j))
              {
                  result = j;
                  j--;
              }
              else
                  i++;
          }
          return result;
      }
  };

int main()
{
    Solution solution;
    vector<vector<int>> given_matrix = {{0, 0}, {1, 1}};
    BinaryMatrix given_binary(given_matrix);
    int expected_anwer = 0;
    assert(solution.leftMostColumnWithOne(given_binary) == expected_anwer);

    given_matrix = {{0, 0}, {0, 0}};
    given_binary = BinaryMatrix(given_matrix);
    expected_anwer = -1;
    assert(solution.leftMostColumnWithOne(given_binary) == expected_anwer);

    return 0;
}
